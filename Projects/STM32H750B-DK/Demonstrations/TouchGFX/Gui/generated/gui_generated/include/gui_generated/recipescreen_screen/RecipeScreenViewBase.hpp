/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef RECIPESCREEN_VIEW_BASE_HPP
#define RECIPESCREEN_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/recipescreen_screen/RecipeScreenPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/scrollers/ScrollList.hpp>
#include <gui/containers/RecipeListElement.hpp>

#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <gui/containers/FpsMcuLoad.hpp>
class RecipeScreenViewBase : public touchgfx::View<RecipeScreenPresenter>
{
public:
    RecipeScreenViewBase();
    virtual ~RecipeScreenViewBase() {}

    virtual void setupScreen();

    virtual void scrollListRecipeSelectorUpdateItem(RecipeListElement& item, int16_t itemIndex)
    {
        // Override and implement this function in RecipeScreen
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image background;
    touchgfx::Image topbar;
    touchgfx::ScrollList scrollListRecipeSelector;
    touchgfx::DrawableListItems<RecipeListElement, 4> scrollListRecipeSelectorListItems;

    touchgfx::IconButtonStyle< touchgfx::ClickButtonTrigger > flexButtonBack;
    touchgfx::TiledImage tiledImageGradientTop;
    touchgfx::TiledImage tiledImageGradientBottom;
    FpsMcuLoad mcuLoad;

private:

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void updateItemCallbackHandler(DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

    /*
     * Callback Declarations
     */
    touchgfx::Callback<RecipeScreenViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<RecipeScreenViewBase, DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;

};

#endif // RECIPESCREEN_VIEW_BASE_HPP
