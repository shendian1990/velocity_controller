/**
 * @file /ocl_controllers/include/ocl_controllers/default_controller.hpp
 *
 * @brief Definition of a simple controller
 *
 * @date Nov 30, 2012
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef DEFAULT_CONTROLLER_HPP_
#define DEFAULT_CONTROLLER_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

namespace ocl
{

/**
 * @brief Controller template
 *
 * Use this class for implementing various controllers.
 */
class Controller
{
public:
  Controller() : controller_active_(false)
  {};
  virtual ~Controller(){};
  /**
   * @brief Initialise the controller
   *
   * Needs to be defined by any class inheriting from SafetyController
   *
   * @return true, if initialisation was succcessful
   */
  virtual bool init() = 0;

  /**
   * @brief Enable the controller
   *
   * @return Returns true, if controller was inactive, false otherwise
   */
  bool enableController()
  {
    if (controller_active_)
    {
      return false;
    }
    else
    {
      controller_active_ = true;
      return true;
    }
  };

  /**
   * @brief Disable the controller
   *
   * @return Returns true, if controller was active, false otherwise
   */
  bool disableController()
  {
    if (!controller_active_)
    {
      return false;
    }
    else
    {
      controller_active_ = false;
      return true;
    }
  };

  /**
   * @brief For complex controlling work
   *
   * If need, implement your complex algorithm here.
   */
  virtual void spin()
  {
    // do nothing
  };

private:
  bool controller_active_;
};

} // namespace ocl

#endif /* DEFAULT_CONTROLLER_HPP_ */