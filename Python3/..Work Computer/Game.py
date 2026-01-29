import pygame
import time
pygame.init()

# Screen/Window
WIDTH = 1000
HEIGHT = 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))

# Clock and FPS
clock = pygame.time.Clock()
FPS = 60  # Frames per second

# Colors
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)
WHITE = (255, 255, 255)

# Fonts
FNTheader = pygame.font.Font(None, 36)
FNTsubheader = pygame.font.Font(None, 24)

# Player Attributes
pWidth = 16
pHeight = 16
pCenterX = pWidth / 2
pCenterY = pHeight / 2
pX = WIDTH / 2 - pCenterX
pY = HEIGHT / 2 - pCenterY

pSpeed = 2
speed_boost = False
speed_boost_start_time = 0

# Variables
round = 1

# Red Circle Attributes
circle_radius = 25
circle_x = 50
circle_y = HEIGHT / 2

# Game Loop
running = True
while running:
    # Event Handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Movement (Keyboard Input)
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and pX > 0:
        pX -= pSpeed
    if keys[pygame.K_RIGHT] and pX < WIDTH - pWidth:
        pX += pSpeed
    if keys[pygame.K_UP] and pY > 0:
        pY -= pSpeed
    if keys[pygame.K_DOWN] and pY < HEIGHT - pHeight:
        pY += pSpeed

    # Collision Detection
    # Check distance between the center of the player and the red circle
    player_center_x = pX + pCenterX
    player_center_y = pY + pCenterY
    distance = ((player_center_x - circle_x) ** 2 + (player_center_y - circle_y) ** 2) ** 0.5

    if distance < circle_radius + pWidth / 2 and not speed_boost:
        speed_boost = True
        speed_boost_start_time = pygame.time.get_ticks()  # Get current time in milliseconds
        pSpeed = 4  # Increase speed

    # Reset speed after 5 seconds
    if speed_boost and pygame.time.get_ticks() - speed_boost_start_time > 5000:
        speed_boost = False
        pSpeed = 2  # Reset speed to normal

    # Fill screen with background color
    screen.fill(BLACK)

    # Draw the red circle (obstacle)
    pygame.draw.circle(screen, RED, (circle_x, int(circle_y)), circle_radius)

    # Draw the player (rectangle)
    pygame.draw.rect(screen, BLUE, (pX, pY, pWidth, pHeight))

    # Display text
    TXTround = FNTheader.render(f"Round: {round}", True, WHITE)
    screen.blit(TXTround, (10, 10))
    TXTpos = FNTsubheader.render(f"X: {player_center_x:.1f} Y: {player_center_y:.1f}", True, WHITE)
    screen.blit(TXTpos, (10, 40))

    if speed_boost:
        TXTboost = FNTsubheader.render("Speed Boost Active!", True, GREEN)
        screen.blit(TXTboost, (10, 60))

    # Update the display
    pygame.display.flip()

    # Limit the frame rate
    clock.tick(FPS)

# Quit Pygame
pygame.quit()
