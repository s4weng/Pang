#ifndef _VISIBLEGAMEOBJECT_H__
#define _VISIBLEGAMEOBJECT_H__

class VisibleGameObject
{
public:
    VisibleGameObject();
    virtual ~VisibleGameObject();

    virtual void Load(std::string filename);
    virtual void Draw(sf::RenderWindow &window);
    virtual void Update(float elapsedTime);

    virtual void SetPosition(float x, float y);
    virtual bool IsLoaded() const;
    virtual float GetWidth() const;
    virtual float GetHeight() const;

    virtual sf::Vector2f GetPosition() const;
    virtual sf::Rect<float> GetBoundingRect() const;

protected:
    sf::Sprite& GetSprite();

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    std::string _filename;
    bool _isLoaded;
};

#endif