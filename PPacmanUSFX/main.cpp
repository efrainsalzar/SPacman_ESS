#include <iostream>
#include "GameObject.h"
#include "GameManager.h"

#include<vector>

using namespace std;


int main(int argc, char* argv[]) {
    GameManager* theApp = GameManager::crearInstancia();

    return theApp->onExecute();
}