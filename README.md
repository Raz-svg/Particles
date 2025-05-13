# Particle Experiment: Bubbles Shape Creation

## Overview

This experiment generates random bubbles that gradually fill the screen. As more bubbles appear, they arrange themselves to form a recognizable shape based on a provided image. The goal of the experiment is to simulate how particles can form a larger structure or image through random placement and movement.

## Features

-   **Random Bubble Generation**: Bubbles are randomly generated on the screen at different positions.
-   **Shape Formation**: As the bubbles fill the screen, they start to take the shape of a given image.
-   **Dynamic Simulation**: The bubble movement is dynamic, creating an interactive visual experience.

## Requirements

-   **C++** (C++11 or later)
-   **SDL3** (Simple DirectMedia Layer 3) for graphics and event handling

## Installation

1.  **Clone this repository:**
    ```bash
    git clone https://github.com/Raz-svg/Particles.git
    cd Particles
    ```

2.  **Install the required dependencies:**
    Make sure you have SDL2 installed on your system. You can download it from [SDL2's official site](https://www.libsdl.org/).

    * **On Linux (Debian/Ubuntu):**
        ```bash
        sudo apt-get update
        sudo apt-get install libsdl2-dev
        ```
    * **On macOS (using Homebrew):**
        ```bash
        brew install sdl2
        ```
    * **On Windows:**
        Follow the instructions on the SDL website for setting up SDL3 with your development environment (e.g., Visual Studio, MinGW). You'll typically need to download the development libraries and configure your project's include and library paths.

3.  **Build the project (using CMake):**
    ```bash
    mkdir build
    cd build
    cmake ..
    make  # Or use your specific build system command, e.g., 'nmake' on Windows with MSVC
    ```

4.  **Run the experiment:**
    * **Linux/macOS:**
        ```bash
        ./particle_experiment
        ```
    * **Windows:**
        ```bash
        .\Debug\particle_experiment.exe 
        # (The exact path might vary based on your build configuration)
        ```

## How It Works

1.  The program loads an image and processes it to determine the target shape (pixels that should contain bubbles).
2.  Random bubbles are generated and assigned initial positions on the screen.
3.  The program continuously updates the simulation:
    * It checks the position of each bubble.
    * Bubbles might be moved or adjusted based on whether their location corresponds to a part of the target image shape.
    * New bubbles might be generated over time.
4.  As the screen fills with bubbles according to the image data, the target shape becomes clearer.

## Customization

-   **Image Input**: You can replace the default image with your own. Place your image file (e.g., `logo.png`, `pattern.bmp`) in the project directory (or a specific assets folder) and update the C++ code where the image is loaded to reference your new file. Ensure your image format is supported by SDL_image if you are using it (common formats like PNG, JPG, BMP are usually fine).
-   **Bubble Properties**: Modify bubble size, color, movement speed, generation rate, etc., within the C++ source code to experiment with different visual effects and simulation behaviors.

## Example Usage

1.  Place an image file (e.g., `target_shape.png`) that you want the bubbles to form into the same directory as the executable, or update the path in the code.
2.  Compile and run the experiment as described in the Installation section.
3.  Watch as the randomly generated bubbles gradually arrange themselves to replicate the shape from your image.

## Contributions

Feel free to fork this project, modify it, and submit pull requests. We welcome contributions to improve the simulation, add new features (like different particle behaviors, interaction, more complex shape processing), or optimize the performance.

## License

This project is licensed under the MIT License - see the `LICENSE` file for details.
