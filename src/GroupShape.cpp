#include "GroupShape.hpp"

namespace NS_COMP{
    GroupShape::GroupShape(std::vector<sf::Shape*> group){
        this->group = group;
    }

    GroupShape::GroupShape() : group(){}

    GroupShape::~GroupShape(){
        for (auto* shape : this->group)
        {
            delete shape;
        }
    }

    void GroupShape::add(sf::Shape* shape) {
        this->group.push_back(shape);
    }

    // Supprime une shape du groupe
    void GroupShape::del(sf::Shape* shape) {
        auto search = std::find(group.begin(), group.end(), shape);
        if (search != this->group.end()) {
            this->group.erase(search); 
        }
    }

    sf::Shape* GroupShape::get(int index){
        return this->group[index];
    }

    void GroupShape::setPosition(float x, float y){
        for (auto* shape : this->group){
            shape->setPosition(x,y);
        }
        
    }

    void GroupShape::setOrigin(float x, float y){
        for (auto* shape : this->group){
            shape->setOrigin(x,y);
        }
    }

    void GroupShape::drawAll(sf::RenderWindow &window){
        for (auto* shape : this->group){
            window.draw(*shape);
        } 
    }

    void GroupShape::move(float x, float y){
        for (auto* shape : this->group){
            shape->move(x,y);
        }
    }
    void GroupShape::scale(float factorX, float factorY){
        for (auto* shape : this->group){
            shape->scale(factorX,factorY);
        }
    }
    void GroupShape::rotate(float angle){
        for (auto* shape : this->group){
            shape->rotate(angle);
        }
    }

    int GroupShape::size(){
        return this->group.size();
    }

    void GroupShape::clear() {
        this->group.clear();
    }
}
