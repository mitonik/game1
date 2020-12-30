#include "Application.hpp"
#define _WIN32_WINNT 0x0500
#include <windows.h> 

int main() {
  HWND hWnd = GetConsoleWindow();
  ShowWindow(hWnd, SW_HIDE);
  Application app;
  app.run();
}