#include "player.h"

Player::Player(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);
    sprite.setTextureRect(sf::IntRect(32,30,265,162));
    sprite.setPosition(320,320);
}
void Player::poruszanie(std::vector<sf::Sprite> &sciany,sf::Time &elapsed)
{
    sprite.setOrigin( (sprite.getLocalBounds().height / 2)-11 , (sprite.getLocalBounds().width / 2) - 10); // potrzebne do rotacji tesktury
    sf::FloatRect player_bounds = sprite.getGlobalBounds();

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.setRotation(-45);
            if(player_bounds.left+player_bounds.width < 1100)
            {
                sprite.move( moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
            if(player_bounds.top > 0)
            {
                sprite.move(0,- moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.setRotation(405);
            if(player_bounds.left+player_bounds.width < 1100)
            {
                sprite.move( moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(- moveSpeed*elapsed.asSeconds(),0);
                    }
                }

            }
            if(player_bounds.top + player_bounds.height < 900)
            {
                sprite.move(0, moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, -moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.setRotation(-135);
            if(player_bounds.left > 0)
            {
                sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
            if(player_bounds.top  > 0)
            {
                sprite.move(0, -moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.setRotation(135);

            if(player_bounds.left > 0)
            {
                sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
            if(player_bounds.top + player_bounds.height < 900)
            {
                sprite.move(0, moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, -moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }
    } else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(player_bounds.top>0)
            {
                sprite.setRotation(270);
                sprite.move(0, -moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(player_bounds.top+player_bounds.height<900)
            {
                sprite.setRotation(-270);
                sprite.move(0, moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0,-moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(player_bounds.left>0)
            {
                sprite.setRotation(180);
                sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if(player_bounds.left+player_bounds.width < 1100)
            {
                sprite.setRotation(0);
                sprite.move( moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
        }
    }

}

sf::Sprite Player::getSpritePlayer() const
{
    return sprite;
}

