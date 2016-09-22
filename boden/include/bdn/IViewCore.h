#ifndef BDN_IViewCore_H_
#define BDN_IViewCore_H_

namespace bdn
{
    class IViewCore;
}

#include <bdn/UiMargin.h>
#include <bdn/Rect.h>
#include <bdn/Nullable.h>
#include <bdn/Size.h>
#include <bdn/View.h>

namespace bdn
{

class IViewCore : BDN_IMPLEMENTS IBase
{
public:


	/** Shows/hides the view core.*/
	virtual void setVisible(const bool& visible)=0;
	
	/** Sets the view core's padding. See View::padding() */
	virtual void setPadding(const Nullable<UiMargin>& padding)=0;

	/** Sets the view core's position. See View::position() */
	virtual void setPosition(const Point& position)=0;

    /** Sets the view core's size. See View::size() */
	virtual void setSize(const Size& size)=0;
    
	
	/** Converts the specified Ui length to DIPs (device independent pixels  - see UiLength::Unit::dip).*/
	virtual double uiLengthToDips(const UiLength& uiLength) const=0;
	

	/** Converts a UiMargin object to a DIP-based margin object (see UiLength::Unit::dip).*/
	virtual Margin uiMarginToDipMargin(const UiMargin& margin) const=0;



	

	/** Asks the view core to calculate its preferred size in DIPs (see UiLength::Unit::dip),
        based on it current content	and properties.
        
		availableWidth and availableHeight are used to indicate the maximum amount of available
		space for the view (also in DIPs). If they are both -1 then that means that the available space should be considered to be unlimited.
		I.e. the function should return the view's optimal size.

		When one of the availableXYZ parameters is not -1 then it means that the available space is limited
		in that dimension. The function should return the preferred size of the view within those constraints,
		trying to not exceed the limited size component.
		
		For example, many views displaying text can handle a limited available width by wrapping the text into
		multiple lines (and thus increasing their height).

		If the view cannot reduce its size to fit into the available space then it is valid for the function
		to return a size that exceeds the available space. However, the layout manager is free to
		size the view to something smaller than the returned preferred size.

		*/	
	virtual Size calcPreferredSize(double availableWidth=-1, double availableHeight=-1) const=0;

	


	/** Called when the outer view's parent has changed.
		
		tryChangeParentView should try to move the core over to the new parent.

		If successful then it should return true, otherwise false.

		If false is returned then this will cause the outer view object to
		automatically re-create the core for the new parent and release the current
		core object.		
		*/
	virtual bool tryChangeParentView(View* pNewParent)=0;
    
    

    /** Returns the number of physical pixels for each DIP (device independent pixel - see UiLength::Unit::dip).
        The number does not have to be an integer. For example, the function could return 2.7 if there are
        2.7 physical pixels for each DIP unit.
        
        The returned value should NOT be stored for later use because it can change at runtime
        (even for the same view object). For example, it can change when the view is moved to a different screen,
        when a view parent changes, when the user changes his monitor settings, and also at other implementation
        specific times. So this should be considered a temporary value.
        */
    virtual double getPhysicalPixelsPerDip() const=0;
	
};


}

#include <bdn/View.h>

#endif
