source 'https://github.com/CocoaPods/Specs.git'

platform :ios, '8.0'
inhibit_all_warnings!

link_with 'ECBToolkit', 'ECBToolkitTests'

pod 'AFNetworking', '3.0.0-beta.1'
pod 'OCMock', :head
pod 'JSONModel', :head

post_install do |installer|
  installer.pods_project.targets.each do |target|
    puts "#{target.name}"
  end
end

