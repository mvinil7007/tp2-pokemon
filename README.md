# TP2 - Simulador de Batalhas Pokémon (INF 112)

<p align="center">
  <img src="lib/assets/banner.png" alt="Iniciais Pokémon em Pixel Art" width="500"/>
</p>

Trabalho Prático desenvolvido para a disciplina de **Programação Orientada a Objetos (INF 112)** na Universidade Federal de Viçosa (UFV).

---

## 🎮 Sobre o Projeto
O **Simulador de Batalhas Pokémon** é um jogo em turnos desenvolvido em **C++**, utilizando a biblioteca **Raylib** para renderização gráfica de interface e reprodução de áudio.

### 🌟 Destaques do Projeto
- **POO Aplicada:** Uso extensivo de Herança, Polimorfismo, Encapsulamento e Abstração.
- **Hierarquia Elementar:** Pokémons e Golpes divididos por tipos (*Fogo*, *Água*, *Planta* e *Elétrico*) com cálculo dinâmico de vantagens de tipo.
- **Ataques Exclusivos por Espécie:** Mapeamento inteligente para garantir golpes específicos para cada espécie.
- **Interface & Sons:** Sprites retrô (estilo FireRed/LeafGreen), sons de combate e interface traduzida em Português.

---

## 📁 Estrutura de Diretórios

```text
tp02/
├── Makefile
├── pokemons.txt
├── lib/                     (bibliotecas fornecidas: raylib, interface, etc.)
└── src/                     (onde ficará todo o seu código)
    ├── main.cpp
    ├── Pendencia.hpp
    ├── Batalha/
    │   ├── Batalha.hpp
    │   └── Batalha.cpp
    ├── Treinador/
    │   ├── Treinador.hpp
    │   └── Treinador.cpp
    ├── Pokemon/
    │   ├── Pokemon.hpp
    │   ├── Pokemon.cpp
    │   ├── PokemonFogo.hpp / PokemonFogo.cpp
    │   ├── PokemonAgua.hpp / PokemonAgua.cpp
    │   ├── PokemonPlanta.hpp / PokemonPlanta.cpp
    │   └── PokemonEletrico.hpp / PokemonEletrico.cpp
    ├── Golpe/
    │   ├── Golpe.hpp
    │   ├── Golpe.cpp
    │   ├── GolpeDano.hpp / GolpeDano.cpp
    │   ├── GolpeCura.hpp / GolpeCura.cpp
    │   └── GolpeReducaoAtaque.hpp / GolpeReducaoAtaque.cpp
    └── Item/
        ├── Item.hpp
        ├── Item.cpp
        ├── Cura.hpp / Cura.cpp
        └── Fortificante.hpp / Fortificante.cpp
```

## 🚀 Como Compilar e Executar

Certifique-se de estar dentro do diretório `tp02/`:

```bash
cd tp02
```

- **Compilar e Executar:**

```bash
make run
```
- **Apenas Compilar:**

```bash
make
```
- **Limpar Arquivos Gerados (`.o` e executável):**

```bash
make clean
```

## 🕹️ Comandos e Controles
- **Mouse / Setas: Navegação pelos menus e seleção de ações.**

- **Clique / Enter: Confirmar escolha de ataque, item ou troca.**

- **Tecla M: Ligar / Desligar música do jogo.**

- **Botão SAIR / X da Janela: Encerrar o jogo com segurança.**

## 📐 Diagrama de Classes (UML)

Estrutura de classes e relacionamentos do sistema (Pokémons, Golpes, Itens e Treinadores):

<p align="center">
  <img src="lib/assets/diagrama_classes.png" alt="Diagrama de Classes UML" width="800"/>
</p>
