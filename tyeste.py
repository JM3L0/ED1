import pygame
import sys
import random

# Inicializar o Pygame
pygame.init()

# Dimensões da tela
WIDTH = 400
HEIGHT = 600

# Cores
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

# Configurações do jogo
FPS = 60
GRAVITY = 0.5
FLAP_STRENGTH = -10
PIPE_SPEED = -5
PIPE_GAP = 150

# Criar a tela
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Flappy Bird")

# Criar o relógio do jogo
clock = pygame.time.Clock()

# Fonte para pontuação
font = pygame.font.Font(None, 36)

# Classe para o pássaro
class Bird:
    def __init__(self):
        self.x = 100
        self.y = HEIGHT // 2
        self.width = 30
        self.height = 30
        self.velocity = 0

    def flap(self):
        self.velocity = FLAP_STRENGTH

    def move(self):
        self.velocity += GRAVITY
        self.y += self.velocity

    def draw(self):
        pygame.draw.rect(screen, BLUE, (self.x, self.y, self.width, self.height))

# Classe para os canos
class Pipe:
    def __init__(self, x):
        self.x = x
        self.top_height = random.randint(50, HEIGHT - PIPE_GAP - 50)
        self.bottom_height = HEIGHT - self.top_height - PIPE_GAP
        self.width = 50

    def move(self):
        self.x += PIPE_SPEED

    def draw(self):
        # Cano superior
        pygame.draw.rect(screen, GREEN, (self.x, 0, self.width, self.top_height))
        # Cano inferior
        pygame.draw.rect(screen, GREEN, (self.x, HEIGHT - self.bottom_height, self.width, self.bottom_height))

    def off_screen(self):
        return self.x + self.width < 0

    def collide(self, bird):
        bird_rect = pygame.Rect(bird.x, bird.y, bird.width, bird.height)
        top_pipe_rect = pygame.Rect(self.x, 0, self.width, self.top_height)
        bottom_pipe_rect = pygame.Rect(self.x, HEIGHT - self.bottom_height, self.width, self.bottom_height)
        return bird_rect.colliderect(top_pipe_rect) or bird_rect.colliderect(bottom_pipe_rect)

# Função principal do jogo
def main():
    bird = Bird()
    pipes = [Pipe(WIDTH)]
    score = 0
    running = True

    while running:
        screen.fill(WHITE)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    bird.flap()

        # Mover e desenhar o pássaro
        bird.move()
        bird.draw()

        # Mover e desenhar os canos
        for pipe in pipes:
            pipe.move()
            pipe.draw()

            if pipe.collide(bird):
                running = False

            if pipe.x + pipe.width < bird.x and not hasattr(pipe, "scored"):
                score += 1
                pipe.scored = True

        # Remover canos fora da tela
        pipes = [pipe for pipe in pipes if not pipe.off_screen()]

        # Adicionar novos canos
        if len(pipes) == 0 or pipes[-1].x < WIDTH // 2:
            pipes.append(Pipe(WIDTH))

        # Verificar colisão com o chão ou o topo
        if bird.y > HEIGHT or bird.y < 0:
            running = False

        # Mostrar pontuação
        score_text = font.render(f"Score: {score}", True, BLACK)
        screen.blit(score_text, (10, 10))

        pygame.display.flip()
        clock.tick(FPS)

if __name__ == "__main__":
    main()
