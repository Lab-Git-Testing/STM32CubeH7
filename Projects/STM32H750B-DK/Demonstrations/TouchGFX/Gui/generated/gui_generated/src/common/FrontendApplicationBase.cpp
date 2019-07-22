/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <gui/hallwayscreen_screen/HallwayScreenView.hpp>
#include <gui/hallwayscreen_screen/HallwayScreenPresenter.hpp>
#include <gui/kitchenscreen_screen/KitchenScreenView.hpp>
#include <gui/kitchenscreen_screen/KitchenScreenPresenter.hpp>
#include <gui/bathtubscreen_screen/BathtubScreenView.hpp>
#include <gui/bathtubscreen_screen/BathtubScreenPresenter.hpp>
#include <gui/bathroomscreen_screen/BathroomScreenView.hpp>
#include <gui/bathroomscreen_screen/BathroomScreenPresenter.hpp>
#include <gui/washerscreen_screen/WasherScreenView.hpp>
#include <gui/washerscreen_screen/WasherScreenPresenter.hpp>
#include <gui/extractorhoodscreen_screen/ExtractorHoodScreenView.hpp>
#include <gui/extractorhoodscreen_screen/ExtractorHoodScreenPresenter.hpp>
#include <gui/recipescreen_screen/RecipeScreenView.hpp>
#include <gui/recipescreen_screen/RecipeScreenPresenter.hpp>
#include <gui/recipeselectedscreen_screen/RecipeSelectedScreenView.hpp>
#include <gui/recipeselectedscreen_screen/RecipeSelectedScreenPresenter.hpp>
#include <gui/ovenscreen_screen/OvenScreenView.hpp>
#include <gui/ovenscreen_screen/OvenScreenPresenter.hpp>
#include <gui/homecontrolscreen_screen/HomeControlScreenView.hpp>
#include <gui/homecontrolscreen_screen/HomeControlScreenPresenter.hpp>
#include <gui/aboutscreen_screen/AboutScreenView.hpp>
#include <gui/aboutscreen_screen/AboutScreenPresenter.hpp>

using namespace touchgfx;


FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    Texts::setLanguage(GB);
}

/*
 * Screen Transition Declarations
 */
// HallwayScreen

void FrontendApplicationBase::gotoHallwayScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHallwayScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoHallwayScreenScreenNoTransitionImpl()
{
    makeTransition<HallwayScreenView, HallwayScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}


void FrontendApplicationBase::gotoHallwayScreenScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHallwayScreenScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoHallwayScreenScreenSlideTransitionWestImpl()
{
    makeTransition<HallwayScreenView, HallwayScreenPresenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}


void FrontendApplicationBase::gotoHallwayScreenScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHallwayScreenScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoHallwayScreenScreenSlideTransitionEastImpl()
{
    makeTransition<HallwayScreenView, HallwayScreenPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}


void FrontendApplicationBase::gotoHallwayScreenScreenCoverTransitionSouth()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHallwayScreenScreenCoverTransitionSouthImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoHallwayScreenScreenCoverTransitionSouthImpl()
{
    makeTransition<HallwayScreenView, HallwayScreenPresenter, touchgfx::CoverTransition<SOUTH>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// KitchenScreen

void FrontendApplicationBase::gotoKitchenScreenScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoKitchenScreenScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoKitchenScreenScreenSlideTransitionEastImpl()
{
    makeTransition<KitchenScreenView, KitchenScreenPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}


void FrontendApplicationBase::gotoKitchenScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoKitchenScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoKitchenScreenScreenNoTransitionImpl()
{
    makeTransition<KitchenScreenView, KitchenScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// BathtubScreen

void FrontendApplicationBase::gotoBathtubScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoBathtubScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoBathtubScreenScreenNoTransitionImpl()
{
    makeTransition<BathtubScreenView, BathtubScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// BathroomScreen

void FrontendApplicationBase::gotoBathroomScreenScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoBathroomScreenScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoBathroomScreenScreenSlideTransitionWestImpl()
{
    makeTransition<BathroomScreenView, BathroomScreenPresenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}


void FrontendApplicationBase::gotoBathroomScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoBathroomScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoBathroomScreenScreenNoTransitionImpl()
{
    makeTransition<BathroomScreenView, BathroomScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// WasherScreen

void FrontendApplicationBase::gotoWasherScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoWasherScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoWasherScreenScreenNoTransitionImpl()
{
    makeTransition<WasherScreenView, WasherScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// ExtractorHoodScreen

void FrontendApplicationBase::gotoExtractorHoodScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoExtractorHoodScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoExtractorHoodScreenScreenNoTransitionImpl()
{
    makeTransition<ExtractorHoodScreenView, ExtractorHoodScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// RecipeScreen

void FrontendApplicationBase::gotoRecipeScreenScreenCoverTransitionSouth()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoRecipeScreenScreenCoverTransitionSouthImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoRecipeScreenScreenCoverTransitionSouthImpl()
{
    makeTransition<RecipeScreenView, RecipeScreenPresenter, touchgfx::CoverTransition<SOUTH>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}


void FrontendApplicationBase::gotoRecipeScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoRecipeScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoRecipeScreenScreenNoTransitionImpl()
{
    makeTransition<RecipeScreenView, RecipeScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// RecipeSelectedScreen

void FrontendApplicationBase::gotoRecipeSelectedScreenScreenCoverTransitionNorth()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoRecipeSelectedScreenScreenCoverTransitionNorthImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoRecipeSelectedScreenScreenCoverTransitionNorthImpl()
{
    makeTransition<RecipeSelectedScreenView, RecipeSelectedScreenPresenter, touchgfx::CoverTransition<NORTH>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// OvenScreen

void FrontendApplicationBase::gotoOvenScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoOvenScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoOvenScreenScreenNoTransitionImpl()
{
    makeTransition<OvenScreenView, OvenScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// HomeControlScreen

void FrontendApplicationBase::gotoHomeControlScreenScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHomeControlScreenScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoHomeControlScreenScreenNoTransitionImpl()
{
    makeTransition<HomeControlScreenView, HomeControlScreenPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// AboutScreen

void FrontendApplicationBase::gotoAboutScreenScreenCoverTransitionNorth()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoAboutScreenScreenCoverTransitionNorthImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoAboutScreenScreenCoverTransitionNorthImpl()
{
    makeTransition<AboutScreenView, AboutScreenPresenter, touchgfx::CoverTransition<NORTH>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

