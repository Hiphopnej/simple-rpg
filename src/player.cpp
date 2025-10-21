#include "player.h"

Player::Player(EntityManager* entityManager, Map *map, Camera *camera, float x, float y) {
    this->entityManager = entityManager;
    this->map = map;
    this->camera = camera;

    this->Load("data/gfx/player.png");
    this->setPosition(x, y);
    this->speed = 0.00015f;;
    this->maxStamina = 3.0f;
    stamina = maxStamina;
}

bool isResting = false;
float restTimer = 5.0f;

void Player::Update(sf::RenderWindow* window, InputManager inputManager, int timeElapsed) {
    float speed = this->speed * timeElapsed;
    // Sprint ability
    // Original speed is multiplied with 3 while sprinting 
    // Player loses 1 stamina per second while sprinting
    // Player regains 1 stamina per second while not sprinting
    float sprintMultiplier;


    if(inputManager.IsPressed(InputManager::SprintAbility) && stamina > 0.0f && isResting == false){
        sprintMultiplier = 3.0f;
        stamina -= 1.0f/60.0f;
    } else if(inputManager.IsPressed(InputManager::SprintAbility) && stamina <= 0.0f && isResting == false){
        sprintMultiplier = 1.0f;
        isResting = true;
    } else if(isResting == true){
        restTimer = restTimer - 1.0f;
        if(restTimer <= 0.0f){
            isResting = false;
            stamina = maxStamina;
            restTimer = 5.0f;
        };
    } else{
        sprintMultiplier = 1.0f;
    }
    // If statement so stamina doesn't surpass max stamina
    if(stamina > maxStamina){
        stamina = maxStamina;
    };

    speed = speed * sprintMultiplier;
    // Update player velocity
    this->velocity.x = inputManager.IsPressed(InputManager::Right) * speed -
                       inputManager.IsPressed(InputManager::Left) * speed;
    this->velocity.y = inputManager.IsPressed(InputManager::Down) * speed -
                       inputManager.IsPressed(InputManager::Up) * speed;

    // Set correct speed on diagonal movement
    if((this->velocity.x == speed || this->velocity.x == -speed)
    && (this->velocity.y == speed || this->velocity.y == -speed)) {
        this->velocity.x *= .75;
        this->velocity.y *= .75;
    }
    
}

float Player::GetSpeed() {
    return this->speed;
}

Player::~Player()
{

}
