import pygame
import random
import sys

# Initialize Pygame
pygame.init()

# Screen Setup
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("10 Rounds RPG Battle")

# Clock and FPS
clock = pygame.time.Clock()
FPS = 60

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)

# Fonts
font = pygame.font.Font(None, 36)

# Player Attributes
player_size = 40
player_speed = 4
player_health = 100
player_rect = pygame.Rect(WIDTH // 2, HEIGHT // 2, player_size, player_size)

# Attack Attributes
is_attacking = False
attack_duration = 200  # milliseconds
attack_cooldown = 500  # cooldown time in milliseconds
last_attack_time = 0

# Enemy Attributes
enemy_size = 30
enemy_speed = 2
enemy_spawn_rate = 2000  # Spawn an enemy every 2 seconds
last_enemy_spawn_time = pygame.time.get_ticks()
enemies = []

# Strong Enemy Attributes
strong_enemy_size = 50
strong_enemy_speed = 3
strong_enemy_health = 3
strong_enemies = []

# Game Variables
current_round = 1
max_rounds = 10
enemies_defeated = 0
enemies_to_defeat = 5
game_over = False
show_round_transition = False
round_transition_time = 0

# Floating Damage Texts
floating_texts = []

# Function to spawn a regular enemy
def spawn_enemy():
    x = random.choice([0, WIDTH - enemy_size])
    y = random.randint(0, HEIGHT - enemy_size)
    enemy = pygame.Rect(x, y, enemy_size, enemy_size)
    enemies.append(enemy)

# Function to spawn a strong enemy
def spawn_strong_enemy():
    x = random.choice([0, WIDTH - strong_enemy_size])
    y = random.randint(0, HEIGHT - strong_enemy_size)
    strong_enemy = {"rect": pygame.Rect(x, y, strong_enemy_size, strong_enemy_size), "health": strong_enemy_health}
    strong_enemies.append(strong_enemy)

# Function to handle game over
def display_game_over(message):
    game_over_text = font.render(message, True, RED)
    screen.blit(game_over_text, (WIDTH // 2 - 80, HEIGHT // 2 - 20))
    pygame.display.update()
    pygame.time.delay(3000)
    pygame.quit()
    sys.exit()

# Function to display round transition
def display_round_transition(round_number):
    transition_text = font.render(f"Round {round_number} Begins!", True, YELLOW)
    screen.blit(transition_text, (WIDTH // 2 - 100, HEIGHT // 2 - 20))

# Main Game Loop
running = True
while running:
    screen.fill(BLACK)
    current_time = pygame.time.get_ticks()

    # Event Handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Show round transition screen
    if show_round_transition and current_time - round_transition_time < 2000:
        display_round_transition(current_round)
    else:
        show_round_transition = False

    # Player Movement
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and player_rect.left > 0:
        player_rect.x -= player_speed
    if keys[pygame.K_RIGHT] and player_rect.right < WIDTH:
        player_rect.x += player_speed
    if keys[pygame.K_UP] and player_rect.top > 0:
        player_rect.y -= player_speed
    if keys[pygame.K_DOWN] and player_rect.bottom < HEIGHT:
        player_rect.y += player_speed

    # Player Attack
    if keys[pygame.K_SPACE] and not is_attacking and current_time - last_attack_time > attack_cooldown:
        is_attacking = True
        last_attack_time = current_time

    if is_attacking and current_time - last_attack_time > attack_duration:
        is_attacking = False

    # Enemy Spawning
    if current_time - last_enemy_spawn_time > max(500, enemy_spawn_rate - (current_round * 150)):
        spawn_enemy()
        last_enemy_spawn_time = current_time

    # Enemy Movement and Collision Detection
    for enemy in enemies[:]:
        if player_rect.x > enemy.x:
            enemy.x += enemy_speed
        if player_rect.x < enemy.x:
            enemy.x -= enemy_speed
        if player_rect.y > enemy.y:
            enemy.y += enemy_speed
        if player_rect.y < enemy.y:
            enemy.y -= enemy_speed

        if player_rect.colliderect(enemy):
            player_health -= 1
            enemies.remove(enemy)
            if player_health <= 0:
                game_over = True

        if is_attacking:
            attack_rect = player_rect.inflate(40, 40)
            if attack_rect.colliderect(enemy):
                enemies.remove(enemy)
                enemies_defeated += 1
                floating_texts.append({"text": "-1", "pos": [enemy.x, enemy.y], "start_time": current_time})

    # Update Floating Damage Texts
    for text in floating_texts[:]:
        if current_time - text["start_time"] > 1000:
            floating_texts.remove(text)
        else:
            text["pos"][1] -= 1

    # Round Progression
    if enemies_defeated >= enemies_to_defeat:
        current_round += 1
        enemies_defeated = 0
        enemies_to_defeat += 3
        show_round_transition = True
        round_transition_time = current_time

        if current_round > max_rounds:
            display_game_over("YOU WIN!")

    # Draw Player
    pygame.draw.rect(screen, BLUE, player_rect)

    # Draw Attack Effect
    if is_attacking:
        attack_rect = player_rect.inflate(40, 40)
        pygame.draw.rect(screen, GREEN, attack_rect, 2)

    # Draw Enemies
    for enemy in enemies:
        pygame.draw.rect(screen, RED, enemy)

    # Draw Floating Damage Texts
    for text in floating_texts:
        damage_surface = font.render(text["text"], True, WHITE)
        screen.blit(damage_surface, text["pos"])

    # Draw Health Bar
    pygame.draw.rect(screen, RED, (10, 10, 200, 20))
    pygame.draw.rect(screen, GREEN, (10, 10, player_health * 2, 20))

    # Display Text (Health, Round, Defeated Count)
    health_text = font.render(f"Health: {player_health}", True, WHITE)
    screen.blit(health_text, (10, 35))
    round_text = font.render(f"Round: {current_round}/{max_rounds}", True, WHITE)
    screen.blit(round_text, (WIDTH - 200, 10))
    defeated_text = font.render(f"Defeated: {enemies_defeated}/{enemies_to_defeat}", True, WHITE)
    screen.blit(defeated_text, (WIDTH - 200, 40))

    # Check for Game Over
    if game_over:
        display_game_over("GAME OVER!")

    # Update Display
    pygame.display.flip()
    clock.tick(FPS)

# Quit Pygame
pygame.quit()