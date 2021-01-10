#include "Postava.hpp"
#include "Strelec.hpp"
#include <memory>

namespace model
{

    Postava::Postava() : m_strelec(std::make_shared<Strelec>()),
                         m_pozicia(0, 0), m_smer(Smer())
    {
        setSprite();
        m_sprite.setPosition(0, 0);
    }

    Postava::Postava(int x, int y) : m_strelec(std::make_shared<Strelec>()),
                                     m_pozicia(x, y),
                                     m_smer(Smer())
    {
        setSprite();
        m_sprite.setPosition(x, y);
    }

    Postava::~Postava()
    {
    }

    std::shared_ptr<Strelec> Postava::getStrelec()
    {
        return m_strelec;
    }

    void Postava::pohyb_na_mape()
    {
    }

    std::pair<int, int> Postava::getPozicia()
    {
        return m_pozicia;
    }

    void Postava::setPozicia(int x, int y)
    {
        m_pozicia.first = x;
        m_pozicia.second = y;
        m_sprite.setPosition(x, y);
    }

    void Postava::setSprite()
    {
        m_strelec->getView().readTextura(m_texture);
        m_sprite.setTexture(m_texture);
        sf::FloatRect spriteSize = m_sprite.getGlobalBounds();
        m_sprite.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
    }

    sf::Sprite Postava::getSprite()
    {
        return m_sprite;
    }

    void Postava::setSmer(bool up, bool down, bool left, bool right)
    {
        m_smer.upFlag = up;
        m_smer.downFlag = down;
        m_smer.leftFlag = left;
        m_smer.rightFlag = right;
    }

    void Postava::setSmer(Smer sm)
    {
        m_smer = sm;
    }

    Smer Postava::getSmer()
    {
        return m_smer;
    }

} // namespace model