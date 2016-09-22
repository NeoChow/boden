#ifndef BDN_RoundDown_H_
#define BDN_RoundDown_H_

#include <bdn/Rounder.h>
#include <cmath>

namespace bdn
{


/** Rounds numbers and various basic types (like Size, Rect, etc.) to
    arbítrary boundaries by rounding down (towards zero).

    The Rounder class takes one parameter in its constructor: the unit.
    It specifies the basic unit to round to. All rounded output values will end up being
    a multiple of this value.
    
    For example, to round to full integers specify 1.

    To round to 2 decimal places specify 0.01.

    You can also specify arbitrary numbers like 12.3456.
    Then all output values will be rounded to a multiple of 12.3456.
    
    The template parameter RoundFunction is used to specify the type of rounding.
    It must be a function that takes a double argument and rounds it to an integer
    value with the desired algorithm. Pass std::round to round to the nearest unit,
    std::ceil to round UP to the next unit and std::floor to round DOWN to the next unit.

    Example:

    \code

    // round to two decimal places
    RoundDown r(0.01);
    
    result = r.round(5.678);
    // returns is 5.67

    // you can also use the call operator
    result = r(5.678);
    // returns the same as calling round (5.67)

    // shortest way to use:
    result = RoundDown(0.01)(5.678);

    
    \endcode
*/
typedef class RoundDown : public Rounder<std::floor>
{
public:
    explicit RoundDown(double unit)
        : Rounder(unit)
	{
	}

};
	

}

#endif
