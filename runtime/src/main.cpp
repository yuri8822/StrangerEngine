#include "core.h"
#include <glad/glad.h>
#include <SDL.h>
#include <iostream>

extern Core core;

int main(int argc, char *argv[]) {
    core.run();

    return 0;
}