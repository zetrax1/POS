#include "hra.hpp"
namespace controler
{

  Hra::Hra(/* args */)
  {
  }

  Hra::~Hra()
  {
  }

  void Hra::setMapa(model::Mapa map)
  {
    m_mapa = map;
  }

  model::Mapa Hra::getMapa()
  {
    return m_mapa;
  }

  void Hra::addNewPostava(model::Postava postava)
  {
    m_postava.push_back(postava);
  }

  model::Postava Hra::getPostava(int i_postava)
  {
    return m_postava[i_postava];
  }

} // namespace controler