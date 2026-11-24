#include "core/io/input.h"
#include "core/io/output.h"

int main()
{
    EagleIO::initialize();

    EagleIO::println("Welcome to EagleCode!");

    EagleIO::print("What is your name? ");

    String name = EagleIO::readLine();

    EagleIO::print("Hello, ");
    EagleIO::print(name);
    EagleIO::println("!");

    return 0;
}