/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef DEVICEINFOWHEELELEMENTS_BASE_HPP
#define DEVICEINFOWHEELELEMENTS_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>

class DeviceInfoWheelElementsBase : public touchgfx::Container
{
public:
    DeviceInfoWheelElementsBase();
    virtual ~DeviceInfoWheelElementsBase() {}

    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

private:

};

#endif // DEVICEINFOWHEELELEMENTS_BASE_HPP
