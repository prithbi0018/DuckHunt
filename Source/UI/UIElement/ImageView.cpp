#include "../../Header/UI/UIElement/ImageView.h"

namespace UI {
	namespace UIElement {
		ImageView::ImageView()
		{
		}
		ImageView::~ImageView()
		{
		}
		void ImageView::initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f postion)
		{
			UIView::initialize();
			if (setTexture(texturePath)) {
				setScale(imageWidth, imageHeight);
				setPosition(postion);
			}
		}
		void ImageView::update()
		{
			UIView::update();
		}
		void ImageView::render()
		{
			UIView::render();
			if (uiState == UIState::VISIBLE) {
				gameWindow->draw(sprite);
			}
		}
		bool ImageView::setTexture(sf::String texturePath)
		{
			if (texture.loadFromFile(texturePath)) {
				sprite.setTexture(texture);
				return true;
			}
			else {
				return false;
			}
		}
		void ImageView::setTextureRect(sf::IntRect textureRect)
		{
			sprite.setTextureRect(textureRect);
		}
		void ImageView::setScale(float xScale, float yScale)
		{
			sprite.setScale(
				xScale / sprite.getTexture()->getSize().x,
				yScale / sprite.getTexture()->getSize().y
			);
		}
		void ImageView::setScale(float width, float height, float tileWidth, float tileHeight)
		{
			sprite.setScale(
				width / tileWidth,
				height / tileHeight
			);
		}
		void ImageView::setPosition(sf::Vector2f position)
		{
			sprite.setPosition(position);
		}
		void ImageView::setRotation(float angle)
		{
			sprite.setRotation(angle);
		}
		void ImageView::setOriginAtCentre()
		{
			sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		}
		void ImageView::setImageAlpha(float alpha)
		{
			sf::Color color = sprite.getColor();
			color.a = alpha;
			sprite.setColor(color);
		}
		void ImageView::setCentreAlinged(bool y)
		{
			sprite.setPosition(
				(gameWindow->getSize().x / 2) - (sprite.getGlobalBounds().width / 2),
				y == true ? (gameWindow->getSize().y / 2) - (sprite.getGlobalBounds().height / 2) : sprite.getGlobalBounds().getPosition().y

			);
		}
		void ImageView::setColor(sf::Color color)
		{
			sprite.setColor(color);
		}
		const sf::Sprite& ImageView::getSprite()
		{
			return sprite;
		}
	}
}