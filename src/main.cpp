#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <Map.hpp>
#include <KeyboardControl.hpp>
#include <iostream>
 
int main()
{

    const unsigned int pixelSize = 16;

    const unsigned int ROWS = 15;
    const unsigned int COLUMNS = 30;

    const unsigned int WIDTH = pixelSize*COLUMNS;
    const unsigned int HEIGHT = pixelSize*ROWS;

    const float aspectRatio = (float)WIDTH/(float)HEIGHT;

    sf::Texture wallTexture("assets/wall.png");
    sf::Texture groundTexture("assets/ground.png");

    sf::Sprite groundSprite(groundTexture);
    sf::Sprite wallSprite(wallTexture);

    std::vector<std::vector<sf::Sprite>> mapSprites{};

    for (int row = 0; row < ROWS; row++) {
        std::vector<sf::Sprite> sprites{};

        for (int column = 0; column < COLUMNS; column++) {

            sf::Sprite* sprite = nullptr;
            
            if (row == 0 || row == ROWS - 1 || column == 0 || column == COLUMNS - 1)
                sprite = &wallSprite;
            else 
                sprite = &groundSprite;

            if (sprite) {
                sprite->setPosition({column * pixelSize, row * pixelSize});
                sprites.push_back(*sprite);
            }
        }
        mapSprites.push_back(sprites);
    }

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Aliens!");
    sf::View view(sf::FloatRect({0, 0}, {WIDTH, HEIGHT})); // Initial view
    window.setFramerateLimit(60);
 
    Map map("FullMap", mapSprites);

    std::vector<Player> players;

    Player player("Gigi", HUMAN, pixelSize/2, "assets/player.png", {pixelSize, pixelSize}, {pixelSize*COLUMNS/2, pixelSize*ROWS/2});
    player.setTextureRect(sf::IntRect({0, 0}, {16, 16}));

    Player playerPaolo("Paolo", HUMAN, pixelSize/2, "assets/player.png", {pixelSize, pixelSize}, {pixelSize*(COLUMNS-3), pixelSize*3});
    playerPaolo.setTextureRect(sf::IntRect({0, 0}, {16, 16}));

    Player playerAndrea("Andrea", HUMAN, pixelSize/2, "assets/player.png", {pixelSize, pixelSize}, {pixelSize*(COLUMNS-3), pixelSize*(ROWS-3)});
    playerAndrea.setTextureRect(sf::IntRect({0, 0}, {16, 16}));

    Player playerMarco("Marco", HUMAN, pixelSize/2, "assets/player.png", {pixelSize, pixelSize}, {pixelSize*3, pixelSize*(ROWS - 3)});
    playerMarco.setTextureRect(sf::IntRect({0, 0}, {16, 16}));

    Player playerCoco("Coco", HUMAN, pixelSize/2, "assets/player.png", {pixelSize, pixelSize}, {pixelSize*3, pixelSize*3});
    playerCoco.setTextureRect(sf::IntRect({0, 0}, {16, 16}));

    players.push_back(playerPaolo);
    players.push_back(playerAndrea);
    players.push_back(playerMarco);
    players.push_back(playerCoco);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();

            if (isMovementEvent(event)) {
                const sf::Keyboard::Key key = event->getIf<sf::Event::KeyPressed>()->code;
                Direction direction = directionKey(key);
                player.move(direction);
            }

            if(event->is<sf::Event::Resized>()) {
                sf::Vector2u size = event->getIf<sf::Event::Resized>()->size;
                float newWidth = size.x; 
                float newHeight = size.y;

                float newAspectRatio = newWidth / newHeight;
                sf::FloatRect viewport({0.f, 0.f}, {1.f, 1.f});

                if (newAspectRatio > aspectRatio) {
                    // Window is too wide, add black bars on the sides
                    float widthFactor = aspectRatio / newAspectRatio;
                    viewport.position.x = (1.f - widthFactor) / 2.f;
                    viewport.size.x = widthFactor;
                } else {
                    // Window is too tall, add black bars on top and bottom
                    float heightFactor = newAspectRatio / aspectRatio;
                    viewport.position.y = (1.f - heightFactor) / 2.f;
                    viewport.size.y = heightFactor;
                }

                view.setSize({WIDTH, HEIGHT}); // Keep the original size of the view
                view.setViewport(viewport); // Apply the viewport to maintain aspect ratio
                window.setView(view);
            }

        }
 
        // Clear screen
        window.clear();
 
        map.draw(window);

        for (Player player : players)
            window.draw(player);
            
        window.draw(player);
 
        // Update the window
        window.display();
    }

}