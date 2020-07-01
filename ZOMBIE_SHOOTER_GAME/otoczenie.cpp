#include "otoczenie.h"

Otoczenie::Otoczenie(sf::Texture &texture_,sf::Texture &podloga_)
{
    //podloga
    podlogatexture=podloga_;
    podlogasprite.setTexture(podlogatexture);
    podlogatexture.setRepeated(true);
    podlogasprite.setScale(0.15,0.15);
    podlogasprite.setTextureRect(sf::IntRect(0,0,1100/0.15,900/0.15));


    //sciany
    this->texture=texture_;
    //lewo gorny rog
    //pion
    sf::Sprite wall1;
    wall1.setTexture(texture);
    texture.setRepeated(true);
    wall1.setScale(0.6, 0.6);
    wall1.setTextureRect(sf::IntRect(-300/0.6,-300/0.6,350/0.6,625/0.6));
    wall1.setPosition(-300,-300);
    sciany.emplace_back(wall1);
    //poziom

    sf::Sprite wall2;
    wall2.setTexture(texture);
    texture.setRepeated(true);
    wall2.setScale(0.6, 0.6);
    wall2.setPosition(0,-300);
    wall2.setTextureRect(sf::IntRect(0/0.6,-300/0.6,400/0.6,350/0.6));
    sciany.emplace_back(wall2);

    //prawy gorny rog
    //poziom
    sf::Sprite wall3;
    wall3.setTexture(texture);
    texture.setRepeated(true);
    wall3.setScale(0.6, 0.6);
    wall3.setPosition(700,-300);
    wall3.setTextureRect(sf::IntRect(700/0.6,-300/0.6,800/0.6,350/0.6));
    sciany.emplace_back(wall3);

    //pion
    sf::Sprite wall4;
    wall4.setTexture(texture);
    texture.setRepeated(true);
    wall4.setScale(0.6, 0.6);
    wall4.setPosition(1050,0);
    wall4.setTextureRect(sf::IntRect(1050/0.6,0/0.6,350/0.6,325/0.6));
    sciany.emplace_back(wall4);

    //dolny lewy rog
    //pion
    sf::Sprite wall5;
    wall5.setTexture(texture);
    texture.setRepeated(true);
    wall5.setScale(0.6, 0.6);
    wall5.setPosition(-300,600);
    wall5.setTextureRect(sf::IntRect(-300/0.6,400/0.6,350/0.6,400/0.6));
    sciany.emplace_back(wall5);
    //poziom
    sf::Sprite wall6;
    wall6.setTexture(texture);
    texture.setRepeated(true);
    wall6.setScale(0.6, 0.6);
    wall6.setPosition(0,850);
    wall6.setTextureRect(sf::IntRect(0/0.6,850/0.6,400/0.6,350/0.6));
    sciany.emplace_back(wall6);
    //prawy dolny rog
    //pion
    sf::Sprite wall7;
    wall7.setTexture(texture);
    texture.setRepeated(true);
    wall7.setScale(0.6, 0.6);
    wall7.setPosition(1050,600);
    wall7.setTextureRect(sf::IntRect(1050/0.6,600/0.6,350/0.6,600/0.6));
    sciany.emplace_back(wall7);
    //poziom
    sf::Sprite wall8;
    wall8.setTexture(texture);
    texture.setRepeated(true);
    wall8.setScale(0.6, 0.6);
    wall8.setPosition(700,850);
    wall8.setTextureRect(sf::IntRect(700/0.6,850/0.6,400/0.6,350/0.6));
    sciany.emplace_back(wall8);

}




// funkcje

void Otoczenie::rysuj(sf::RenderWindow &window_)
{
    window_.draw(podlogasprite);
    for(auto &el : sciany)
    {
        window_.draw(el);
    }
}

std::vector<sf::Sprite> Otoczenie::getScianyVectorSprite() const
{
    return sciany;
}
