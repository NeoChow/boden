
#import <bdn/ios/ButtonCore.hh>

@interface BdnIosButtonClickManager : NSObject

@property(nonatomic, assign) std::weak_ptr<bdn::Button> outer;

@end

@implementation BdnIosButtonClickManager

- (void)clicked
{
    if (auto outer = self.outer.lock()) {
        bdn::ClickEvent clickEvent(outer);
        outer->onClick().notify(clickEvent);
    }
}

@end

namespace bdn
{
    namespace ios
    {

        UIButton *ButtonCore::_createUIButton(std::shared_ptr<Button> outer)
        {
            return [UIButton buttonWithType:UIButtonTypeSystem];
        }

        ButtonCore::ButtonCore(std::shared_ptr<Button> outer) : ViewCore(outer, _createUIButton(outer))
        {
            _button = (UIButton *)getUIView();

            _clickManager = [BdnIosButtonClickManager alloc];
            _clickManager.outer = outer;

            [_button addTarget:_clickManager action:@selector(clicked) forControlEvents:UIControlEventTouchUpInside];

            setLabel(outer->label);
        }

        ButtonCore::~ButtonCore()
        {
            [_button removeTarget:_clickManager action:nil forControlEvents:UIControlEventTouchUpInside];
        }

        UIButton *ButtonCore::getUIButton() { return _button; }

        void ButtonCore::setLabel(const String &label)
        {
            [_button setTitle:stringToNSString(label) forState:UIControlStateNormal];
        }

        double ButtonCore::getFontSize() const { return _button.titleLabel.font.pointSize; }
    }
}
