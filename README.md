# Resource Manager
A simple resource manager for SFML written in C++

## Requirements
You need to install SFML
<pre>
sudo apt install libsfml-dev
</pre>

## Usage
First load your resources in the init function into ResourceManager.cpp
```c++
void init()
{
    loadTexture("myTexture","path/to/texture.png");
    loadTexture("myImage","path/to/image.png");
    loadTexture("myMusic","path/to/music.ogg");
    loadTexture("myFont","path/to/font.ttf");
}
```
 - myTexture, myImage, myMusic, myFont are the names of the resources you load
 - path/to/smth is the path of your resource

Now you can use them in your script
```c++
#include "ResourceManager.h"

int main()
{
    const unsigned int screenWidth = 800;
    const unsigned int screenHeight = 600;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Resource Manager Example");

    ResourceManager::init();

    sf::Sprite mySprite;
    mySprite.setTexture(ResourceManager::texture("myTexture"));
    
    std::cout << ResourceManager::image("myImage").getSize().x << std::endl;
    
    //whatever you want

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(mySprite);
        window.display();
    }
}
```
So the syntax is 
<pre>
ResourceManager::[resource type]([resource name])
</pre>

## Compile your project
<pre>
g++ -o [program name] [your script.cpp] src/ResourceManager.cpp -I src -lsfml-system -lsfml-window -lsfml-graphics
</pre>
Where "program name" is your program name and "your script.cpp" is your script path
