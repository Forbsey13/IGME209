#include "Tank.h"
#include "TankMap.h"

Tank::Tank(Texture* baseTexture_ptr, Texture* turretTexture_ptr, Vector2f position)
{
    m_baseSprite.setTexture(*baseTexture_ptr); // assign the base texture to base sprite
    m_turretSprite.setTexture(*turretTexture_ptr); // assign the turretTexture to turret sprite

    // init origin
    m_baseSprite.setOrigin(baseTexture_ptr->getSize().x / 2.0f, baseTexture_ptr->getSize().y / 2.0f);
    m_turretSprite.setOrigin(turretTexture_ptr->getSize().x / 2.0f, turretTexture_ptr->getSize().y / 2.0f);

    // init position
    m_baseSprite.setPosition(position);
    m_turretSprite.setPosition(position);

    // init rotation
    m_baseSprite.setRotation(0);
    m_turretSprite.setRotation(0);

    // init scale
    float scale = (float)m_tank_size / baseTexture_ptr->getSize().x;
    m_baseSprite.setScale(scale, scale);
    m_turretSprite.setScale(scale, scale);
}

Tank::~Tank()
{
}

void Tank::Render(RenderWindow& window)
{
    window.draw(m_baseSprite);// draw the base sprite
    window.draw(m_turretSprite);// draw the base sprite
}

void Tank::Update(RenderWindow& window, float deltaSeconds)
{
    UpdateBaseTransformation(window, deltaSeconds);
    UpdateTurretRotation(deltaSeconds);
    UpdateFire();
    UpdateView(window);
}

void Tank::Fire()
{
    cout << "Fire!" << endl;
}

void Tank::UpdateBaseTransformation(RenderWindow& window, float deltaSeconds)
{
    Vector2f movement = Vector2f(0, 0);
    float rotation = m_baseSprite.getRotation();

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        movement.y -= 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        movement.y += 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        movement.x -= 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        movement.x += 1.0f;
    }

    if (movement.x != 0.0f || movement.y != 0.0f) {
        // +90 if the sprite's default orientation is up
        rotation = std::atan2(movement.y, movement.x) * 180.0f / PI + 90;

        // Normalize the movement vector to ensure consistent speed in all directions
        float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
        movement /= length;
    }

    Vector2f newPosition = m_baseSprite.getPosition() + m_move_speed * deltaSeconds * movement;
    if (newPosition.y < 0.0f) newPosition.y = 0.0f;
    if (newPosition.y > window.getSize().y) newPosition.y = window.getSize().y;
    if (newPosition.x < 0.0f) newPosition.x = 0.0f;
    if (newPosition.x > window.getSize().x) newPosition.x = window.getSize().x;

    if (TankMap::s_instance->CheckTankPassable(newPosition, Vector2f(m_tank_size, m_tank_size))) {
        // set position
        m_baseSprite.setPosition(newPosition);
        m_turretSprite.setPosition(newPosition);
    }

    // set rotation
    m_baseSprite.setRotation(rotation);
    // m_turretSprite.setRotation(rotation); // If you want the turret rotate with the base
}

void Tank::UpdateTurretRotation(float deltaSeconds)
{
    if (Keyboard::isKeyPressed(Keyboard::J))
        m_turretSprite.rotate(-m_turret_rotate_speed * deltaSeconds);
    if (Keyboard::isKeyPressed(Keyboard::K))
        m_turretSprite.rotate(m_turret_rotate_speed * deltaSeconds);
}

void Tank::UpdateFire()
{
    if (m_is_fire_button_down == false && Keyboard::isKeyPressed(Keyboard::Space)) {
        this->Fire();
    }
    m_is_fire_button_down = Keyboard::isKeyPressed(Keyboard::Space);
}

void Tank::UpdateView(RenderWindow& window)
{
    // change camera view type
    if (m_view_type == FOCUS) {
        View view = window.getView();
        view.setCenter(m_baseSprite.getPosition());
        view.setSize(window.getDefaultView().getSize() / 2.0f); // change size if you want
        window.setView(view);
    }

    if (m_is_camera_switch_button_down == false && Keyboard::isKeyPressed(Keyboard::C)) {
        m_view_type = (VIEW_TYPE)((m_view_type + 1) % 2);

        if (m_view_type == VIEW_TYPE::FREE) {
            View view = window.getDefaultView();
            window.setView(view);
        }
    }
    m_is_camera_switch_button_down = Keyboard::isKeyPressed(Keyboard::C);
}
