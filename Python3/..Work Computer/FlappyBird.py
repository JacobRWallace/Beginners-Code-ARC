import pygame
import sys
import random

# Initialize pygame
pygame.init()

# Screen dimensions
SCREEN_WIDTH = 1000
SCREEN_HEIGHT = 600
SCREEN = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Flappy Bird")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (135, 206, 250)
GREEN = (0, 200, 0)

# Bird properties
BIRD_WIDTH = 30
BIRD_HEIGHT = 30
bird_x = 50
bird_y = SCREEN_HEIGHT // 2
bird_velocity = 0 
gravity = 0.5
jump_strength = -8

# Pipe properties
PIPE_WIDTH = 60
PIPE_HEIGHT = random.randint(150, 400)
PIPE_GAP = 150
pipe_x = SCREEN_WIDTH
pipe_velocity = -4

# Game variables
score = 0
font = pygame.font.Font(None, 36)
clock = pygame.time.Clock()
FPS = 60

def draw_bird(x, y):
    pygame.draw.ellipse(SCREEN, GREEN, (x, y, BIRD_WIDTH, BIRD_HEIGHT))

def draw_pipe(x, height):
    pygame.draw.rect(SCREEN, BLACK, (x, 0, PIPE_WIDTH, height))  # Top pipe
    pygame.draw.rect(SCREEN, BLACK, (x, height + PIPE_GAP, PIPE_WIDTH, SCREEN_HEIGHT - (height + PIPE_GAP)))  # Bottom pipe

def check_collision(bird_x, bird_y, pipe_x, pipe_height):
    # Bird hits top or bottom of the screen
    if bird_y < 0 or bird_y + BIRD_HEIGHT > SCREEN_HEIGHT:
        return True
    # Bird hits pipes
    if (pipe_x < bird_x + BIRD_WIDTH < pipe_x + PIPE_WIDTH):
        if bird_y < pipe_height or bird_y + BIRD_HEIGHT > pipe_height + PIPE_GAP:
            return True
    return False

# Game loop
running = True
while running:
    SCREEN.fill(BLUE)

    # Event handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                bird_velocity = jump_strength

    # Bird movement
    bird_velocity += gravity
    bird_y += bird_velocity

    # Pipe movement
    pipe_x += pipe_velocity
    if pipe_x + PIPE_WIDTH < 0:  # Reset pipe when it moves off-screen
        pipe_x = SCREEN_WIDTH
        PIPE_HEIGHT = random.randint(150, 400)
        score += 1

    # Draw everything
    draw_bird(bird_x, bird_y)
    draw_pipe(pipe_x, PIPE_HEIGHT)

    # Display score
    score_text = font.render(f"Score: {score}", True, WHITE)
    SCREEN.blit(score_text, (10, 10))

    # Check for collisions
    if check_collision(bird_x, bird_y, pipe_x, PIPE_HEIGHT):
        print(f"Game Over! Final Score: {score}")
        pygame.quit()
        sys.exit()

    # Update the display and tick the clock
    pygame.display.flip()
    clock.tick(FPS)
