#pragma once
#include "../../Header/UI/UIElement/UIView.h"

namespace UI {
	namespace UIElement {
		class ImageView : public UIView {
		protected:
			sf::Texture texture;
			sf::Sprite sprite;
		public:
			ImageView();
			virtual ~ImageView() override;
			virtual void initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f postion);
			virtual void update() override;
			virtual void render() override;
			virtual bool setTexture(sf::String texturePath);
			virtual void setTextureRect(sf::IntRect textureRect);
			virtual void setScale(float xScale, float yScale);
			virtual void setScale(float width, float height, float tileWidth, float tileHeight);
			virtual void setPosition(sf::Vector2f position);
			virtual void setRotation(float angle);
			virtual void setOriginAtCentre();
			virtual void setImageAlpha(float alpha);
			virtual void setCentreAlinged(bool y);
			virtual void setColor(sf::Color color);

			const virtual sf::Sprite& getSprite();

		};
	}
}