//#include <iostream>
//#include "SFML/Graphics.hpp"
//#include <cstdlib>  
//#include <ctime>  
//#include <random>
//#include <SFML/Audio.hpp>
//using namespace std;
//using namespace sf;
//
//enum GameState {
//    menu,
//    play,
//    color_change,
//    exi, pause
//};
//GameState currentState;
//class player;
//class enemies;
//class movement;
//class maze;
//class menu;
//class food;
//class score_manager;
//Font highSpeedFont;
//class gameloop;
//class Maze {
//
//    RectangleShape wallShape;
//    static const int grid_w = 48;
//    static const int grid_h = 27;
//    int walls[grid_w][grid_h] = { 0 };
//    Texture backgroundTexture;
//    Sprite backgroundSprite;
//
//public:
//    Maze() {
//        setupWalls();
//        wallShape.setSize(Vector2f(40.f, 40.f));
//        wallShape.setFillColor(Color(255, 153, 51));
//        wallShape.setOutlineThickness(4.f);
//        wallShape.setOutlineColor(Color::White);
//        if (!backgroundTexture.loadFromFile("C:/C++/2nd Semester/OOP Project/OOP Project/background.png")) {
//            cerr << "Failed to load background texture!" << endl;
//        }
//        else {
//            backgroundTexture.setRepeated(true);
//            backgroundSprite.setTexture(backgroundTexture);
//            backgroundSprite.setTextureRect(IntRect(0, 0, 1920, 1080));
//        }
//
//    }
//
//
//    void setupWalls() {
//        // Clear grid
//        for (int x = 0; x < grid_w; x++) {
//            for (int y = 0; y < grid_h; y++) {
//                walls[x][y] = 0;
//            }
//        }
//
//
//        for (int x = 0; x < grid_w; x++) {
//            walls[x][0] = 1;
//            walls[x][grid_h - 1] = 1;
//        }
//        for (int y = 0; y < grid_h; y++) {
//            walls[0][y] = 1;
//            walls[grid_w - 1][y] = 1;
//        }
//
//
//        for (int x = 2; x <= 10; x++) walls[x][2] = 1;
//        for (int x = 13; x <= 34; x++) walls[x][2] = 1;
//        for (int x = 37; x <= 45; x++) walls[x][2] = 1;
//
//
//        for (int x = 5; x <= 8; x++) walls[x][5] = 1;
//        for (int x = 39; x <= 42; x++) walls[x][5] = 1;
//        for (int x = 10; x <= 14; x++) walls[x][7] = 1;
//        for (int x = 33; x <= 37; x++) walls[x][7] = 1;
//
//
//        for (int y = 4; y <= 10; y++) walls[23][y] = 1;
//        for (int y = 4; y <= 10; y++) walls[24][y] = 1;
//
//
//        for (int x = 20; x <= 27; x++) walls[x][12] = 1;
//        for (int x = 20; x <= 27; x++) walls[x][15] = 1;
//        for (int y = 13; y <= 14; y++) {
//            walls[20][y] = 1;
//            walls[27][y] = 1;
//        }
//        walls[20][20] = 0;
//
//        walls[20][13] = 0;
//        walls[20][14] = 0;
//        walls[27][13] = 0;
//        walls[27][14] = 0;
//
//        for (int x = 10; x <= 14; x++) walls[x][18] = 1;
//        for (int x = 33; x <= 37; x++) walls[x][18] = 1;
//
//
//        for (int y = 18; y <= 23; y++) walls[6][y] = 1;
//        for (int y = 18; y <= 23; y++) walls[41][y] = 1;
//
//
//        for (int x = 5; x <= 12; x++) walls[x][24] = 1;
//        for (int x = 35; x <= 42; x++) walls[x][24] = 1;
//
//
//        for (int x = 2; x <= 5; x++) walls[x][20] = 1;
//        for (int x = 42; x <= 45; x++) walls[x][20] = 1;
//        walls[23][15] = 0;
//        walls[24][15] = 0;
//
//        for (int y = 8; y <= 10; y++) walls[16][y] = 1;
//        for (int y = 8; y <= 10; y++) walls[31][y] = 1;
//
//
//        for (int y = 17; y <= 19; y++) walls[23][y] = 1;
//        for (int y = 17; y <= 19; y++) walls[24][y] = 1;
//
//
//        for (int x = 18; x <= 30; x++) walls[x][25] = 1;
//    }
//    bool canMoveTo(Vector2f position, float radius) {
//
//        Vector2f points[4] = {
//            position + Vector2f(radius, 0),
//            position - Vector2f(radius, 0),
//            position + Vector2f(0, radius),
//            position - Vector2f(0, radius)
//        };
//
//
//        for (int i = 0; i < 4; i++) {
//            if (isWall(points[i])) {
//                return false;
//            }
//        }
//        return true;
//    }
//    void draw(RenderWindow& window) {
//        window.draw(backgroundSprite);
//        for (int x = 0; x < grid_w; x++) {
//            for (int y = 0; y < grid_h; y++) {
//                if (walls[x][y] == 1) {
//                    wallShape.setPosition(x * 40.f, y * 40.f);
//
//                    window.draw(wallShape);
//                }
//            }
//        }
//    }
//
//    bool isWall(Vector2f position) const {
//        int gridX = (position.x / 40);
//        int gridY = (position.y / 40);
//
//        if (gridX < 0 || gridY < 0 || gridX >= grid_w || gridY >= grid_h) {
//            return true;
//        }
//
//        return walls[gridX][gridY] == 1;
//    }
//};
//
//class movement {
//public:
//    Vector2f lastValidDir;
//    float lastValidRotation;
//
//    movement() : lastValidDir(0.f, 0.f), lastValidRotation(0.f) {}
//    void input(player& p, Maze& m);
//
//
//
//};
//
//class player : public movement {
//public:
//    vector<Color> colors = { Color::Yellow, Color::Cyan, Color::Magenta, Color::White };
//    int color_index = 0;
//
//    float color_change_timer = 0.0f;
//    float color_change_delay = 0.2f;
//    sf::Clock colorClock;
//    CircleShape pacman;
//    bool is_player;
//    Vector2f direction = { 0, 0 };
//    float speed = 5.0f;
//    bool blockedByWall = false;
//    Texture pacTex;
//    Vector2f defaultPosition = { 100.f, 1080 / 2.0f };
//    player() {
//        sf::Image pacImg;
//        pacImg.loadFromFile("C:/C++/2nd Semester/OOP Project/OOP Project/Annotation 2025-05-14 140522.png");
//        pacImg.createMaskFromColor(sf::Color::Black);
//        blockedByWall = false;
//
//
//        pacTex.loadFromImage(pacImg);
//
//
//        pacman.setRadius(15.f);
//        pacman.setOrigin(15.f, 15.f);
//        pacman.setTexture(&pacTex);
//        pacman.setRadius(15.f);
//        pacman.setFillColor(Color::Yellow);
//        pacman.setPosition(100.0f, 1080 / 2.0f);
//
//        is_player = true;
//    }
//    void update(Maze& maze) {
//        if (blockedByWall) return;
//
//        FloatRect futureBounds = pacman.getGlobalBounds();
//        futureBounds.left += direction.x * speed;
//        futureBounds.top += direction.y * speed;
//        futureBounds.width -= 4.f;
//        futureBounds.height -= 4.f;
//        futureBounds.left += 2.f;
//        futureBounds.top += 2.f;
//
//
//        bool collision = false;
//        for (int x = 0; x < 48; x++) {
//            for (int y = 0; y < 27; y++) {
//                if (maze.isWall(Vector2f(x * 40.f + 20.f, y * 40.f + 20.f))) {
//                    FloatRect wallBounds(x * 40.f, y * 40.f, 40.f, 40.f);
//                    if (futureBounds.intersects(wallBounds)) {
//                        collision = true;
//                        break;
//                    }
//                }
//            }
//            if (collision) break;
//        }
//
//        if (!collision) {
//            pacman.move(direction * speed);
//        }
//        else {
//            direction = Vector2f(0, 0);
//            blockedByWall = true;
//        }
//    }
//
//
//    void resetPosition() {
//        pacman.setPosition(defaultPosition);
//        direction = Vector2f(0, 0);
//        blockedByWall = false;
//
//        lastValidDir = Vector2f(0.f, 0.f);
//        lastValidRotation = 0.f;
//    }
//
//
//    void pdraw(RenderWindow& window) {
//        window.draw(pacman);
//    }
//
//    Vector2f getPosition() const {
//        return pacman.getPosition();
//    }
//
//    FloatRect getBounds() const {
//        return pacman.getGlobalBounds();
//    }
//    void move_(Vector2f delta) {
//        pacman.move(delta);
//    }
//    void cycleColor() {
//        this->getplayer().setPosition(1920 / 2.0f, 1080 / 2.0f);
//        if (colorClock.getElapsedTime().asSeconds() >= color_change_delay) {
//            if (Keyboard::isKeyPressed(Keyboard::Left)) {
//                color_index = (color_index - 1 + colors.size()) % colors.size();
//                pacman.setFillColor(colors[color_index]);
//                colorClock.restart();
//            }
//            else if (Keyboard::isKeyPressed(Keyboard::Right)) {
//                color_index = (color_index + 1) % colors.size();
//                pacman.setFillColor(colors[color_index]);
//                colorClock.restart();
//            }
//        }
//    }
//
//    CircleShape& getplayer() {
//        return this->pacman;
//    }
//
//    ~player() {}
//};
//
//void movement::input(player& p, Maze& maze) {
//
//    float speed = 0.0f;
//    Vector2f pos = p.pacman.getPosition();
//
//    float rotation = p.pacman.getRotation();
//
//    Vector2f inputDir(0.f, 0.f);
//
//
//    static GameState lastState = currentState;
//    if (lastState != currentState && currentState == play) {
//        lastValidDir = Vector2f(0.f, 0.f);
//
//    }
//    lastState = currentState;
//
//    // Reset lastValidDir if the game state just transitioned to play
//
//
//
//        // Get new input
//    if (Keyboard::isKeyPressed(Keyboard::A)) {
//        inputDir = Vector2f(-1.f, 0.f);
//        rotation = 180.f;
//        speed = 5.0f;
//    }
//    else if (Keyboard::isKeyPressed(Keyboard::D)) {
//        inputDir = Vector2f(1.f, 0.f);
//        rotation = 0.f;
//        speed = 5.0f;
//    }
//    else if (Keyboard::isKeyPressed(Keyboard::W)) {
//        inputDir = Vector2f(0.f, -1.f);
//        rotation = 270.f;
//
//    }
//    else if (Keyboard::isKeyPressed(Keyboard::S)) {
//        inputDir = Vector2f(0.f, 1.f);
//        rotation = 90.f;
//        speed = 5.0f;
//    }
//
//    // If there's new input, update last valid direction
//    if (inputDir.x != 0.f || inputDir.y != 0.f) {
//        lastValidDir = inputDir;
//        lastValidRotation = rotation;
//    }
//
//    // Always try to move in last valid direction if there was any movement
//    if (lastValidDir.x != 0.f || lastValidDir.y != 0.f) {
//        // Predict bounding box after move
//        FloatRect futureBounds = p.pacman.getGlobalBounds();
//        futureBounds.left += lastValidDir.x * p.speed;
//        futureBounds.top += lastValidDir.y * p.speed;
//
//
//        futureBounds.left += 2.f;
//        futureBounds.top += 2.f;
//        futureBounds.width -= 4.f;
//        futureBounds.height -= 4.f;
//
//        bool collision = false;
//
//        for (int x = 0; x < 48; x++) {
//            for (int y = 0; y < 27; y++) {
//                Vector2f wallPos(x * 40.f + 20.f, y * 40.f + 20.f);
//                if (maze.isWall(wallPos)) {
//                    FloatRect wallBounds(x * 40.f, y * 40.f, 40.f, 40.f);
//                    if (futureBounds.intersects(wallBounds)) {
//                        collision = true;
//                        break;
//                    }
//                }
//            }
//            if (collision) break;
//        }
//
//        if (!collision) {
//            p.pacman.move(lastValidDir.x * p.speed, lastValidDir.y * p.speed);
//            p.pacman.setRotation(lastValidRotation);
//        }
//    }
//}
//
//
//
//
//class Ghost {
//protected:
//public: CircleShape shape;
//      Vector2f direction;
//      float speed;
//      Color color;
//      Vector2f scatterTarget;
//      Clock behaviorClock;
//      float chaseDuration = 20.0f;
//      float scatterDuration = 7.0f;
//      bool isScattering = false;
//      int stuckFrames = 0;
//      const int maxStuckFrames = 10;
//      Vector2f lastPosition;
//public:bool vulnerable = false;
//      Clock powerClock;
//      Vector2f spawnPosition;
//public:
//    Ghost(Color ghostColor, Vector2f startPos, Vector2f scatterTarget)
//        : color(ghostColor), scatterTarget(scatterTarget) {
//        shape.setRadius(15.f);
//        shape.setFillColor(ghostColor);
//        shape.setPosition(startPos);
//        shape.setOrigin(20.f, 20.f);
//        speed = 3.0f;
//        direction = getRandomDirection();
//    }
//
//    virtual Vector2f getChaseTarget(const player& p) = 0;
//    void update(Maze& maze, const player& p) {
//
//
//        if (isScattering && behaviorClock.getElapsedTime().asSeconds() > scatterDuration) {
//            isScattering = false;
//            behaviorClock.restart();
//        }
//        else if (!isScattering && behaviorClock.getElapsedTime().asSeconds() > chaseDuration) {
//            isScattering = true;
//            behaviorClock.restart();
//        }
//
//        Vector2f currentPos = shape.getPosition();
//        Vector2f target;
//
//        if (vulnerable) {
//            // Calculate opposite direction from player
//            Vector2f fromPlayer = shape.getPosition() - p.getPosition();
//            target = shape.getPosition() + fromPlayer * 3.f;  // Move away
//        }
//        else {
//            target = isScattering ? scatterTarget : getChaseTarget(p);
//        }
//
//
//        // Get available directions (not blocked by walls)
//        vector<Vector2f> availableDirections;
//        Vector2f directions[4] = {
//            Vector2f(1, 0), Vector2f(-1, 0),
//            Vector2f(0, 1), Vector2f(0, -1)
//        };
//
//        // Don't allow 180-degree turns (except when stuck)
//        Vector2f oppositeDir = -direction;
//
//        for (int i = 0; i < 4; i++) {
//            Vector2f dir = directions[i];
//            if (dir != oppositeDir || availableDirections.empty()) {
//                FloatRect testBounds = shape.getGlobalBounds();
//                testBounds.left += dir.x * speed;
//                testBounds.top += dir.y * speed;
//
//                bool blocked = false;
//                for (int x = 0; x < 48 && !blocked; x++) {
//                    for (int y = 0; y < 27 && !blocked; y++) {
//                        if (maze.isWall(Vector2f(x * 40.f + 20.f, y * 40.f + 20.f))) {
//                            FloatRect wallBounds(x * 40.f, y * 40.f, 40.f, 40.f);
//                            if (testBounds.intersects(wallBounds)) {
//                                blocked = true;
//                            }
//                        }
//                    }
//                }
//
//                if (!blocked) {
//                    availableDirections.push_back(dir);
//                }
//            }
//        }
//
//
//        if (!availableDirections.empty()) {
//            Vector2f bestDir = availableDirections[0];
//            float minDistance = FLT_MAX;
//
//            for (int i = 0; i < availableDirections.size(); ++i) {
//                Vector2f dir = availableDirections[i];
//                Vector2f newPos = currentPos + dir * speed;
//                float dx = target.x - newPos.x;
//                float dy = target.y - newPos.y;
//                float distance = sqrt(dx * dx + dy * dy);
//                if (distance < minDistance) {
//                    minDistance = distance;
//                    bestDir = dir;
//                }
//            }
//
//
//            direction = bestDir;
//            shape.move(direction * speed);
//        }
//
//        else if (availableDirections.empty()) {
//            direction = oppositeDir;
//            shape.move(direction * speed);
//        }
//        if (shape.getPosition() == lastPosition) {
//            stuckFrames++;
//            if (stuckFrames > maxStuckFrames) {
//
//                direction = getRandomDirection();
//                stuckFrames = 0;
//            }
//        }
//        else {
//            stuckFrames = 0;
//        }
//        lastPosition = shape.getPosition();
//    }
//    void makeVulnerable() {
//        vulnerable = true;
//        powerClock.restart();
//        shape.setFillColor(Color::Blue);
//    }
//
//
//    void updateVulnerability() {
//        if (vulnerable && powerClock.getElapsedTime().asSeconds() > 10.f) {
//            vulnerable = false;
//            shape.setFillColor(color); // return to original color
//        }
//    }
//
//    void resetPosition() {
//
//        shape.setPosition(spawnPosition);
//        direction = getRandomDirection();
//        vulnerable = false;
//        shape.setFillColor(color);
//        isScattering = false;
//        behaviorClock.restart();
//        stuckFrames = 0;
//
//    }
//    bool isPathBlocked(Maze& maze, const Vector2f& position, const Vector2f& direction) {
//        int gridX = (position.x / 40);
//        int gridY = (position.y / 40);
//
//        // Only check 3x3 area around current position
//        for (int x = max(0, gridX - 1); x <= min(47, gridX + 1); x++) {
//            for (int y = max(0, gridY - 1); y <= min(26, gridY + 1); y++) {
//                if (maze.isWall(Vector2f(x * 40.f + 20.f, y * 40.f + 20.f))) {
//                    FloatRect wallBounds(x * 40.f, y * 40.f, 40.f, 40.f);
//                    FloatRect ghostBounds = shape.getGlobalBounds();
//                    ghostBounds.left += direction.x * speed;
//                    ghostBounds.top += direction.y * speed;
//
//                    if (ghostBounds.intersects(wallBounds)) {
//                        return true;
//                    }
//                }
//            }
//        }
//        return false;
//    }
//    void draw(RenderWindow& window) {
//        window.draw(shape);
//    }
//
//    FloatRect getBounds() const {
//        return shape.getGlobalBounds();
//    }
//    float distanceToPlayer(const player& p) const {
//        Vector2f delta = shape.getPosition() - p.getPosition();
//        return sqrt(delta.x * delta.x + delta.y * delta.y);
//    }
//
//    Vector2f getRandomDirection() {
//        int dir = rand() % 4;
//        if (dir == 0) {
//            return Vector2f(1, 0);
//        }
//        else if (dir == 1) {
//            return Vector2f(-1, 0);
//        }
//        else if (dir == 2) {
//            return Vector2f(0, 1);
//        }
//        else {
//            return Vector2f(0, -1);
//        }
//    }
//};
//
//class Blinky : public Ghost {
//public:
//    Blinky(Vector2f startPos) : Ghost(Color::Red, startPos, Vector2f(1840, 40)) {
//        spawnPosition = startPos;
//    }
//
//    Vector2f getChaseTarget(const player& p) override {
//        // Blinky targets Pac-Man directly
//        return p.getPosition();
//    }
//};
//
//class Pinky : public Ghost {
//public:
//    Pinky(Vector2f startPos) : Ghost(Color(255, 192, 203), startPos, Vector2f(40, 40)) {
//        spawnPosition = startPos;
//    }
//
//    Vector2f getChaseTarget(const player& p) override {
//        float dist = distanceToPlayer(p);
//        if (dist >= 80.f && dist <= 160.f) {
//            // Within 2–4 tiles, go directly for the player
//            return p.getPosition();
//        }
//
//        // Otherwise, normal Pinky logic (4 tiles ahead)
//        Vector2f pacDir = p.direction;
//        // if (pacDir == Vector2f(0, 0)) pacDir = Vector2f(-1, 0);
//        return p.getPosition() + pacDir * 160.f; // 4 tiles ahead
//    }
//};
//
//class Inky : public Ghost {
//public:
//
//
//    Inky(Vector2f startPos) : Ghost(Color::Cyan, startPos, Vector2f(1840, 1040)) {
//        spawnPosition = startPos;
//    }
//
//    Vector2f getChaseTarget(const player& p) override {
//        // Inky uses Blinky's position to calculate target
//        Vector2f blinkyPos = shape.getPosition(); // Simplified - should get actual Blinky's position
//        Vector2f pacDir = p.direction;
//        //if (pacDir == Vector2f(0, 0)) pacDir = Vector2f(-1, 0);
//
//        Vector2f tempTarget = p.getPosition() + pacDir * 80.f; // 2 tiles ahead
//        return tempTarget * 2.f - blinkyPos; // Mirror position relative to tempTarget
//    }
//};
//
//class Food {
//protected:
//    CircleShape shape;
//    bool eaten;
//public:
//    Food(float radius, Color color, Vector2f position) {
//        shape.setRadius(radius);
//        shape.setFillColor(color);
//        shape.setPosition(position);
//        eaten = false;
//        shape.setOrigin(radius, radius); // Center the origin
//    }
//
//    bool isEaten() { return eaten; }
//    void setEaten(bool value) { eaten = value; }
//
//    virtual void draw(RenderWindow& window) {
//        if (!eaten) {
//            window.draw(shape);
//        }
//    }
//
//    FloatRect getBounds() {
//        return shape.getGlobalBounds();
//    }
//};
//
//// Regular food pellet
//class Pellet : public Food {
//public:
//    Pellet(Vector2f position) : Food(3.f, Color::White, position) {}
//};
//class PowerPellet : public Food {
//public:
//    PowerPellet(Vector2f position) : Food(6.f, Color::Yellow, position) {}
//};
//
//class FoodManager {
//private:
//    static const int gridSize = 40;
//    Maze& maze;
//public:  Food* foods[48][27];
//
//
//public:
//    FoodManager(Maze& m) : maze(m) {
//
//        for (int x = 0; x < 48; x++) {
//            for (int y = 0; y < 27; y++) {
//                foods[x][y] = nullptr;
//            }
//        }
//
//        for (int x = 1; x < 46; x++) {
//            for (int y = 1; y < 26; y++) {
//                Vector2f pos(x * gridSize + gridSize / 2, y * gridSize + gridSize / 2);
//                if (!maze.isWall(pos)) {
//                    // Create power pellets at corners
//                    if ((x == 1 && y == 1) || (x == 46 && y == 25)) {
//                        foods[x][y] = new PowerPellet(pos);
//                    }
//                    else {
//                        foods[x][y] = new Pellet(pos);
//                    }
//                }
//            }
//        }
//    }
//
//    ~FoodManager() {
//
//        for (int x = 0; x < 48; x++) {
//            for (int y = 0; y < 27; y++) {
//                if (foods[x][y] != nullptr) {
//                    delete foods[x][y];
//                }
//            }
//        }
//    }
//    void reset() {
//        for (int x = 0; x < 48; x++) {
//            for (int y = 0; y < 27; y++) {
//                if (foods[x][y] != nullptr) {
//                    delete foods[x][y];
//                    Vector2f pos(x * gridSize + gridSize / 2, y * gridSize + gridSize / 2);
//                    if (!maze.isWall(pos)) {
//                        // Recreate power pellets at corners
//                        if ((x == 1 && y == 1) || (x == 46 && y == 25)) {
//                            foods[x][y] = new PowerPellet(pos);
//                        }
//                        else {
//                            foods[x][y] = new Pellet(pos);
//                        }
//                    }
//                }
//            }
//        }
//    }
//    void checkCollision(CircleShape& player) {
//        FloatRect playerBounds = player.getGlobalBounds();
//
//        for (int x = 0; x < 48; x++) {
//            for (int y = 0; y < 27; y++) {
//                if (foods[x][y] != nullptr && !foods[x][y]->isEaten()) {
//                    if (playerBounds.intersects(foods[x][y]->getBounds())) {
//                        foods[x][y]->setEaten(true);
//
//                    }
//                }
//            }
//        }
//    }
//    bool allFoodEaten() {
//        for (int x = 0; x < 48; x++) {
//            for (int y = 0; y < 27; y++) {
//                if (foods[x][y] != nullptr && !foods[x][y]->isEaten()) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//    void draw(RenderWindow& window) {
//        for (int x = 0; x < 48; x++) {
//            for (int y = 0; y < 27; y++) {
//                if (foods[x][y] != nullptr) {
//                    foods[x][y]->draw(window);
//                }
//            }
//        }
//    }
//};
//
//
//class Menu {
//public:
//    CircleShape pacman;
//    Texture backgroundTexture;
//    Sprite backgroundSprite;
//    Text playButton, exitButton, changeColorButton;
//    int selected_option;
//    RectangleShape overlay;
//    Clock keyClock;
//    Music menuMusic;
//
//    Menu() {
//        selected_option = 0;
//        currentState = menu;
//        if (!menuMusic.openFromFile("C:/C++/2nd Semester/OOP Project/OOP Project/Abyss.ogg")) {
//            std::cerr << "Error: Could not load menu background music!" << std::endl;
//        }
//        menuMusic.setLoop(true);
//        menuMusic.play();
//
//
//        if (!backgroundTexture.loadFromFile("C:/C++/2nd Semester/OOP Project/OOP Project/pacman.png")) {
//            std::cerr << "Error: Could not load menu background texture!" << std::endl;
//
//            // Fallback background
//            Image tempImage;
//            tempImage.create(1920, 1080, Color(20, 20, 80));
//            backgroundTexture.create(1920, 1080);
//            backgroundTexture.update(tempImage);
//        }
//
//
//        backgroundSprite.setTexture(backgroundTexture);
//
//
//        Vector2u windowSize = { 1920, 1080 };
//        Vector2u textureSize = backgroundTexture.getSize();
//
//        backgroundSprite.setScale(
//            float(windowSize.x) / textureSize.x,
//            float(windowSize.y) / textureSize.y
//        );
//
//
//        overlay.setSize(Vector2f(1920, 1080));
//        overlay.setFillColor(Color(0, 0, 0, 150));
//
//        setupMenu();
//    }
//
//
//    void setupMenu() {
//        playButton.setFont(highSpeedFont);
//        playButton.setString("Play");
//        playButton.setCharacterSize(40);
//        playButton.setPosition(800.f, 300.f);
//
//        changeColorButton.setFont(highSpeedFont);
//        changeColorButton.setString("Change Color");
//        changeColorButton.setCharacterSize(40);
//        changeColorButton.setPosition(800.f, 400.f);
//
//        exitButton.setFont(highSpeedFont);
//        exitButton.setString("Exit");
//        exitButton.setCharacterSize(40);
//        exitButton.setPosition(800.f, 500.f);
//    }
//
//    void update() {
//
//        playButton.setFillColor(Color::White);
//        changeColorButton.setFillColor(Color::White);
//        exitButton.setFillColor(Color::White);
//
//        if (selected_option == 0) playButton.setFillColor(Color::Yellow);
//        else if (selected_option == 1) changeColorButton.setFillColor(Color::Yellow);
//        else if (selected_option == 2) exitButton.setFillColor(Color::Yellow);
//    }
//
//    void handleInput(RenderWindow& window) {
//        float laststrokeTime = 0.2f;
//
//        if (keyClock.getElapsedTime().asSeconds() > laststrokeTime) {
//            if (Keyboard::isKeyPressed(Keyboard::Up)) {
//                selected_option--;
//                if (selected_option < 0) selected_option = 2;
//                keyClock.restart();
//            }
//            else if (Keyboard::isKeyPressed(Keyboard::Down)) {
//                selected_option++;
//                if (selected_option > 2) selected_option = 0;
//                keyClock.restart();
//            }
//            else if (Keyboard::isKeyPressed(Keyboard::RShift)) {
//                if (selected_option == 0) {
//                    currentState = play;
//
//                    menuMusic.stop();
//                }
//                else if (selected_option == 1) {
//                    currentState = color_change;
//
//                }
//                else if (selected_option == 2) {
//                    currentState = exi;
//                    menuMusic.stop();
//                    window.close();
//                }
//                keyClock.restart();
//
//            }
//            else if (Keyboard::isKeyPressed(Keyboard::P) && currentState == play) {
//                currentState = pause;
//                keyClock.restart();
//            }
//            else if (Keyboard::isKeyPressed(Keyboard::P) && currentState == pause) {
//                currentState = play;
//                keyClock.restart();
//            }
//        }
//    }
//
//    void render(RenderWindow& window) {
//        window.clear(Color::Black);
//
//        window.draw(backgroundSprite);
//        update();
//        window.draw(playButton);
//        window.draw(changeColorButton);
//        window.draw(exitButton);
//        window.display();
//    }
//
//    GameState getState() {
//        return currentState;
//    }
//
//    void resetState() {
//        currentState = menu;
//    }
//
//};
//class ScoreManager {
//private:
//    int totalScore;
//    int foodScore;
//    int ghostScore;
//    Text totalScoreText;
//    Text foodScoreText;
//
//    Font& font;
//
//
//    Clock multiplierClock;
//
//
//public:
//    ScoreManager(Font& fontRef) :
//        font(fontRef),
//        totalScore(0),
//        foodScore(0),
//        ghostScore(0)
//
//    {
//
//        totalScoreText.setFont(font);
//        totalScoreText.setCharacterSize(40);
//        totalScoreText.setFillColor(Color::White);
//        totalScoreText.setPosition(50.f, 20.f);
//        totalScoreText.setLetterSpacing(1.5f);
//
//        foodScoreText.setFont(font);
//        foodScoreText.setCharacterSize(30);
//        foodScoreText.setFillColor(Color::Green);
//        foodScoreText.setPosition(50.f, 70.f);
//
//
//
//        updateAllTexts();
//    }
//
//
//    void addFoodScore(int points) {
//        foodScore += points;
//        totalScore += points;
//        updateAllTexts();
//    }
//
//
//    void addGhostScore(int points) {
//
//
//        totalScore += points;
//
//        updateAllTexts();
//    }
//
//
//
//
//    void reset() {
//        totalScore = 0;
//        foodScore = 0;
//
//
//        updateAllTexts();
//    }
//
//
//    void draw(RenderWindow& window) {
//        window.draw(totalScoreText);
//        window.draw(foodScoreText);
//
//    }
//
//private:
//    void updateAllTexts() {
//        totalScoreText.setString("TOTAL: " + to_string(totalScore));
//        foodScoreText.setString("Food: " + to_string(foodScore));
//
//    }
//};
//class Gameloop {
//public:
//    Menu gameMenu;
//    player p1;
//    movement m1;
//    ScoreManager* scoreManager;
//
//    Maze m2;
//    Blinky* blinky;
//    Pinky* pinky;
//    Inky* inky;
//    FoodManager* foodManager;
//    Clock clock;
//    float timer = 0.0f;
//    float delay = 0.01f;
//
//
//    Text livesText;
//    Text pauseText;
//    Text youWonText;
//    bool wonGame = false;
//    Clock winClock;
//    Clock pauseClock;
//    int lives = 3;
//    bool gameOver = false;
//    float ghostReleaseDelay = 4.0f;
//    Ghost* ghostQueue[3];
//    int nextGhostIndex = 0;
//    Clock gameOverClock;
//    Clock ghostReleaseClock;
//    Text gameOverText;
//    Gameloop() : foodManager(new FoodManager(m2)) {
//        blinky = new Blinky(Vector2f(920, 550));
//        pinky = new Pinky(Vector2f(960, 570));
//        inky = new Inky(Vector2f(940, 560));
//        scoreManager = new ScoreManager(highSpeedFont);
//        ghostQueue[0] = blinky;
//        ghostQueue[1] = pinky;
//        ghostQueue[2] = inky;
//        livesText.setFont(highSpeedFont);
//        livesText.setCharacterSize(30);
//        livesText.setFillColor(Color::White);
//        livesText.setPosition(50.f, 160.f);
//        pauseText.setFont(highSpeedFont);
//        pauseText.setString("GAME PAUSED\nPress P to Continue");
//        pauseText.setCharacterSize(60);
//        pauseText.setFillColor(Color::Yellow);
//        pauseText.setStyle(Text::Bold);
//        youWonText.setFont(highSpeedFont);
//        youWonText.setString("YOU WON!");
//        youWonText.setCharacterSize(80);
//        youWonText.setFillColor(Color::Green);
//        youWonText.setStyle(Text::Bold);
//
//        FloatRect wonRect = youWonText.getLocalBounds();
//        youWonText.setOrigin(wonRect.left + wonRect.width / 2.0f, wonRect.top + wonRect.height / 2.0f);
//        youWonText.setPosition(1920 / 2.0f, 1080 / 2.0f);
//
//        // Center the text
//        FloatRect textRect = pauseText.getLocalBounds();
//        pauseText.setOrigin(textRect.left + textRect.width / 2.0f,
//            textRect.top + textRect.height / 2.0f);
//        pauseText.setPosition(1920 / 2.0f, 1080 / 2.0f);
//
//
//        pauseText.setLineSpacing(1.5f);
//        gameOverText.setFont(highSpeedFont);
//        gameOverText.setString("GAME OVER");
//        gameOverText.setCharacterSize(80);
//        gameOverText.setFillColor(Color::Red);
//        gameOverText.setStyle(Text::Bold);
//
//        FloatRect goRect = gameOverText.getLocalBounds();
//        gameOverText.setOrigin(goRect.left + goRect.width / 2.0f, goRect.top + goRect.height / 2.0f);
//        gameOverText.setPosition(1920 / 2.0f, 1080 / 2.0f);
//    }
//    void releaseGhosts() {
//        if (ghostReleaseClock.getElapsedTime().asSeconds() >= ghostReleaseDelay) {
//            if (nextGhostIndex < 3) { // Only release if within array bounds
//                Ghost* nextGhost = ghostQueue[nextGhostIndex];
//                nextGhost->resetPosition();  // Release it from its position
//                nextGhostIndex++;
//                ghostReleaseClock.restart(); // Restart clock for the next one
//            }
//        }
//    }
//    void render(RenderWindow& wind) {
//
//        if (gameMenu.getState() == menu) {
//
//            if (gameMenu.getState() == menu) {
//                if (gameMenu.menuMusic.getStatus() != SoundSource::Playing) {
//                    gameMenu.menuMusic.play();
//                }
//                gameMenu.render(wind);
//            }
//            else {
//                gameMenu.menuMusic.stop();
//            }
//
//
//            gameMenu.render(wind);
//        }
//        else if (gameMenu.getState() == play || gameMenu.getState() == pause) {
//            wind.clear(Color::Black);
//            m2.draw(wind);
//            p1.pdraw(wind);
//            blinky->draw(wind);
//            pinky->draw(wind);
//
//            inky->draw(wind);
//
//            RectangleShape scoreBackground(Vector2f(300, 50));
//            scoreBackground.setPosition(20.f, 20.f);
//            scoreBackground.setFillColor(Color::Black);
//            wind.draw(scoreBackground);
//            foodManager->draw(wind);
//            scoreManager->draw(wind);
//            wind.draw(livesText);
//
//            if (gameMenu.getState() == pause) {
//
//                RectangleShape overlay(Vector2f(1920, 1080));
//                overlay.setFillColor(Color(0, 0, 0, 150));
//                wind.draw(overlay);
//
//                wind.draw(pauseText);
//            }
//
//        }
//        else if (gameMenu.getState() == color_change) {
//
//            wind.clear(Color::Black);
//            p1.pdraw(wind);
//
//        }
//        if (gameOver) {
//            RectangleShape overlay(Vector2f(1920, 1080));
//            overlay.setFillColor(Color(0, 0, 0, 200));
//            wind.draw(overlay);
//            wind.draw(gameOverText);
//        }
//        if (wonGame) {
//            RectangleShape overlay(Vector2f(1920, 1080));
//            overlay.setFillColor(Color(0, 0, 0, 200));
//            wind.draw(overlay);
//            wind.draw(youWonText);
//        }
//        wind.display();
//    }
//    void resetGhosts() {
//        blinky->resetPosition();
//        pinky->resetPosition();
//        inky->resetPosition();
//
//        // Reset ghost states
//        blinky->vulnerable = false;
//        pinky->vulnerable = false;
//        inky->vulnerable = false;
//
//        nextGhostIndex = 0;
//        ghostReleaseClock.restart();
//        blinky->shape.setFillColor(blinky->color);
//        pinky->shape.setFillColor(pinky->color);
//        inky->shape.setFillColor(inky->color);
//    }
//    void update() {
//        if (gameOver) {
//            if (gameOverClock.getElapsedTime().asSeconds() > 2.0f) {
//
//                resetGhosts();
//                gameOver = false;
//
//                lives = 3;
//                p1.resetPosition();
//                currentState = menu;
//
//                resetGhosts();
//                scoreManager->reset();
//                // Reset food
//                foodManager->reset();
//            }
//            return;
//        }
//        if (wonGame) {
//            if (winClock.getElapsedTime().asSeconds() > 2.0f) {
//                lives = 3;
//                wonGame = false;
//                resetGhosts();
//                p1.resetPosition();
//                currentState = menu;
//
//                resetGhosts();
//                scoreManager->reset();
//                // Reset food
//                foodManager->reset();
//            }
//            return;
//        }
//
//
//        if (gameMenu.getState() == play) {
//
//
//
//            p1.input(p1, m2);
//
//            releaseGhosts(); // Handle timed ghost releases
//
//
//            if (nextGhostIndex > 0) blinky->update(m2, p1);
//            if (nextGhostIndex > 1) pinky->update(m2, p1);
//            if (nextGhostIndex > 2) inky->update(m2, p1);
//
//            p1.update(m2);
//
//
//
//            FloatRect playerBounds = p1.getplayer().getGlobalBounds();
//            playerBounds.left -= 2.f;
//            playerBounds.top -= 2.f;
//            playerBounds.width += 4.f;
//            playerBounds.height += 4.f;
//
//            for (int x = 0; x < 48; x++) {
//                for (int y = 0; y < 27; y++) {
//                    if (foodManager->foods[x][y] != nullptr && !foodManager->foods[x][y]->isEaten()) {
//                        if (playerBounds.intersects(foodManager->foods[x][y]->getBounds())) {
//                            foodManager->foods[x][y]->setEaten(true);
//                            // Trigger power mode if it's a PowerPellet
//
//                            if (dynamic_cast<PowerPellet*>(foodManager->foods[x][y]) != nullptr) {
//                                scoreManager->addFoodScore(50);
//                                blinky->makeVulnerable();
//                                pinky->makeVulnerable();
//                                inky->makeVulnerable();
//                            }
//                            else {
//                                scoreManager->addFoodScore(10);
//                            }
//                        }
//                    }
//                }
//            }
//            if (foodManager->allFoodEaten()) {
//                wonGame = true;
//                winClock.restart();
//                return;
//            }
//            livesText.setString("Lives: " + to_string(lives));
//
//
//            if (p1.getBounds().intersects(inky->getBounds())) {
//                if (inky->vulnerable) {
//
//                    scoreManager->addGhostScore(200);
//                    inky->resetPosition();
//                    inky->vulnerable = false;
//                }
//                else {
//                    lives--;
//                    if (lives <= 0) {
//                        gameOver = true;
//                        scoreManager->reset();
//                        p1.resetPosition();
//                        gameOverClock.restart();
//                    }
//                    else {
//                        p1.resetPosition();
//                    }
//                }
//            }
//
//            if (p1.getBounds().intersects(pinky->getBounds())) {
//                if (pinky->vulnerable) {
//                    scoreManager->addGhostScore(200);
//                    pinky->resetPosition();
//                    pinky->vulnerable = false;
//                }
//                else {
//                    lives--;
//                    if (lives <= 0) {
//                        gameOver = true;
//                        p1.resetPosition();
//                        gameOverClock.restart();
//                    }
//                    else {
//                        p1.resetPosition();
//                    }
//                }
//            }
//
//            if (p1.getBounds().intersects(blinky->getBounds())) {
//                if (blinky->vulnerable) {
//                    scoreManager->addGhostScore(200);
//                    blinky->resetPosition();
//                    blinky->vulnerable = false;
//
//                }
//                else {
//                    lives--;
//                    if (lives <= 0) {
//                        gameOver = true;
//                        gameOverClock.restart();
//                    }
//                    else {
//                        p1.resetPosition();
//                    }
//                }
//            }
//
//            blinky->updateVulnerability();
//            pinky->updateVulnerability();
//            inky->updateVulnerability();
//
//        }
//        else if (gameMenu.getState() == color_change) {
//            p1.getplayer().setPosition(1920 / 2.0f, 1080 / 2.0f);
//            p1.cycleColor();
//        }
//
//        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
//            if (currentState == color_change) {
//                currentState = menu;
//                p1.resetPosition();
//            }
//            else {
//                currentState = play;
//                p1.resetPosition();
//            }
//        }
//    }
//
//
//
//
//
//
//
//    void rungame(RenderWindow& wind) {
//        wind.setVerticalSyncEnabled(true);
//
//        while (wind.isOpen()) {
//            Event event;
//
//            while (wind.pollEvent(event)) {
//                if (event.type == Event::Closed) {
//                    wind.close();
//                }
//                if (event.type == Event::KeyPressed && event.key.code == Keyboard::P) {
//                    if (currentState == play) currentState = pause;
//                    else if (currentState == pause) currentState = play;
//                }
//            }
//
//            if (gameMenu.getState() == menu) {
//                gameMenu.handleInput(wind);
//                lives = 3;
//                gameMenu.render(wind);
//            }
//            else if (gameMenu.getState() == play) {
//                cout << " hello:" << endl;
//                wind.clear();
//                update();       // For play mode
//                render(wind);   // Render game elements
//            }
//            else if (gameMenu.getState() == color_change) {
//                cout << "Buh";
//                wind.clear();
//                update();
//                render(wind);
//            }
//
//            else if (gameMenu.getState() == pause) {
//
//                update();
//                render(wind);
//            }
//        }
//    }
//
//
//};
//
//int main() {
//    srand(time(0));
//    if (!highSpeedFont.loadFromFile("C:/C++/2nd Semester/OOP Project/OOP Project/High Speed.ttf")) {
//        std::cerr << "Error loading font!" << std::endl;
//    }
//    RenderWindow window(VideoMode(1920, 1080), "PACMAN GAME");
//    Gameloop g1;
//    g1.rungame(window);
//
//    return 0;
//}