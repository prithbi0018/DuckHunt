#include "../../Header/UI/UIElement/UIView.h"
#include "../../../Header/Global/ServiceLocator.h"
namespace UI {
	namespace UIElement {
		UIView::UIView()
		{
		}
		UIView::~UIView()
		{
		}
		void UIView::initialize()
		{
			gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			show();
		}
		void UIView::update()
		{
		}
		void UIView::render()
		{
		}
		void UIView::show()
		{
			uiState = UIState::VISIBLE;
		}
		void UIView::hide()
		{
			uiState = UIState::HIDDEN;
		}
	}
}