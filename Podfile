# Uncomment the next line to define a global platform for your project
# platform :ios, '9.0'

target 'TmapSDK_pod' do
  # Comment the next line if you don't want to use dynamic frameworks
    use_frameworks!

  # Pods for TMapView

 pod 'CombineExt'
  pod 'Solar'
  pod 'Interpolate'
  pod 'TinyConstraints'
  pod 'PinLayout'
  pod 'Alamofire'
  pod 'KeychainAccess'
  pod 'MarqueeLabel'
  pod 'FlexLayout'
  pod 'CombineCocoa'
  pod 'Kingfisher'
  pod 'CocoaSecurity'
  pod 'AloeStackView'
  pod 'RxGesture'
  pod 'SwiftReorder'
  pod 'SwiftSimplify'
  pod 'RxSwift'
  pod 'RxCocoa'
  pod 'ReactorKit'
  pod 'CocoaMQTT'

end


post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings['BUILD_LIBRARY_FOR_DISTRIBUTION'] = 'YES'
      config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '13.0'
    end
  end
end
