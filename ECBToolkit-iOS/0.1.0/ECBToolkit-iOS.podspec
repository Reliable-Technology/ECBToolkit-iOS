#
# Be sure to run `pod lib lint ECBToolkit-iOS.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name                = 'ECBToolkit-iOS'
  s.version             = '0.1.0'
  s.license             = { :type => 'Commercial', :text => "See http://www.ecom.bid/terms" }
  s.homepage            = 'http://www.ecom.bid'
  s.summary             = 'ECBToolkit-iOS is a neat package that helps developer communicate to eComBid-API'
  s.author              = { "Tony Kieu" => "tkieu87@gmail.com" }

  s.source              = { :git => "https://github.com/Reliable-Technology/ECBToolkit-iOS.git", :tag => s.version.to_s }

  s.platform            = :ios, '8.0'

  s.requires_arc        = true

  s.source_files        = 'ECBToolkit/*.{h,m}',
                          'ECBToolkit/Internal/**/*.{h,m}'
  #s.resources           = 'ECBToolkit/Resources/*'

  s.ios.frameworks      = 'AudioToolbox',
                          'CFNetwork',
                          'CoreGraphics',
                          'CoreLocation',
                          'QuartzCore',
                          'Security',
                          'StoreKit',
                          'SystemConfiguration'
  s.ios.weak_frameworks = 'Accounts',
                          'Social'

  s.dependency 'AFNetworking'

end
