# IDJ 2026-1 - Basic Engine


## SLD MAC

```sh
brew install sdl2
brew install sdl2_image
brew install sdl2_mixer
```


### Update Makefile MAC configuration
```sh
ifeq ($(UNAME_S), Darwin)
    # 1. Adiciona o caminho do Homebrew para os headers e bibliotecas
    INC_PATHS += -I/opt/homebrew/include
    LINK_PATH += -L/opt/homebrew/lib
    
    # 2. Usa as flags de biblioteca normais em vez de frameworks
    LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
endif
```


● Soma de Rect com Vec2