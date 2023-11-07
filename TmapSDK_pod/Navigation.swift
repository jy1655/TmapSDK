//
//  Navigation.swift
//  TmapSDK_pod
//
//  Created by 황재영 on 11/6/23.
//

import TmapUISDK
import TmapNaviSDK
import Combine

enum RouteRequestType {
    case onlyDestination(destination: Point)
    case direct(origin: Point, destination: Point)
    case withWaypoints(origin: Point, destination: Point, waypoints: [Point])
} // 경로 요청을 위한 enum

class Navigation {

    static let shared = Navigation()

    private init() {}

    var sdkConfig = UISDKConfigOption()
    var authCancelable: Set<AnyCancellable> = []
    private var locationAlert: UIAlertController? = nil

    // main 화면 세로 고정
//    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
//        return UIInterfaceOrientationMask.portrait
//    }
//
//    override var preferredInterfaceOrientationForPresentation: UIInterfaceOrientation {
//        return UIInterfaceOrientation.portrait
//    }



    func setConfig(on mapViewDelegate: UISDKMapViewDelegate) {

        sdkConfig.mapTextSize = .large                      // map의 text의 크기를 설정합니다.
        sdkConfig.isUseSpeedReactMapScale = true            // 속도반응형 지도의 사용여부를 설정합니다.
        sdkConfig.mapViewDelegate = mapViewDelegate
        TmapUISDKManager.shared.setConfig(config: sdkConfig)
    }


    func requestNavi(type: RouteRequestType) {
        // 경로 설정

        switch type {
        case .onlyDestination(let destination):
            print("경로 요청: 현위치에서 출발")
            TmapUISDKManager.shared.requestRoute(
                destination: destination
            )


        case .direct(let origin, let destination):
                    // 경로 요청 로직
            print("경로 요청: 직접 경로")
            TmapUISDKManager.shared.requestRoute(
                origin: origin,
                destination: destination
            )

        case .withWaypoints(let origin, let destination, let waypoints):
                    // 경로 요청 로직
            print("경로 요청: 경유지 포함")
            TmapUISDKManager.shared.requestRoute(
                origin: origin,
                destination: destination,
                wayPoints: waypoints
            )}
        }

    func locationCheck(on viewController: UIViewController) {

        print("location check")

        let status = CLLocationManager.authorizationStatus()

        let logOkAction = UIAlertAction(title: "네", style: UIAlertAction.Style.default){
            (action: UIAlertAction) in
            if #available(iOS 10.0, *) {
                UIApplication.shared.open(NSURL(string:UIApplication.openSettingsURLString)! as URL)
            } else {
                UIApplication.shared.openURL(NSURL(string: UIApplication.openSettingsURLString)! as URL)
            }
        }
        let logNoAction = UIAlertAction(title: "아니오", style: UIAlertAction.Style.destructive){
            (action: UIAlertAction) in
            exit(0)
        }

        if status == CLAuthorizationStatus.denied || status == CLAuthorizationStatus.restricted {
            setAlert(title: "위치권한 설정이 '안함'으로 되어있습니다.", message: "앱 설정 화면으로 가시겠습니까? \n '아니오'를 선택하시면 앱이 종료됩니다.", actions: [logOkAction, logNoAction], on: viewController)
        }
    }

    func hideLocationAlert(from viewController: UIViewController) {
        guard let alert = self.locationAlert else {
            return
        }
        print("hide location permission alert")
        viewController.dismiss(animated: false)

        self.locationAlert = nil
    }

    func showLocationAlert(on viewController: UIViewController) {
        guard self.locationAlert == nil else { return }

        let logOkAction = UIAlertAction(title: "네", style: UIAlertAction.Style.default){
            (action: UIAlertAction) in
            let url = URL.init(string: UIApplication.openSettingsURLString)
            if #available(iOS 10.0, *) {
                UIApplication.shared.open(url!)
            } else {
                UIApplication.shared.openURL(url!)
            }
            self.locationAlert = nil
        }
        let logNoAction = UIAlertAction(title: "아니오", style: UIAlertAction.Style.destructive){
            (action: UIAlertAction) in
            self.locationAlert = nil
            exit(0)
        }

        setAlert(title: "위치 권한 및 정확한 위치를 허용해 주세요.",
                 message: "앱 설정 화면으로 가시겠습니까? \n '아니오'를 선택하시면 앱이 종료됩니다.",
                 actions: [logOkAction, logNoAction],
                 on: viewController)
        print("show location permission alert")

    }

    /**
     주행정보

     >  경로안내 또는 안심주행 동작 시 내부적으로 처리되는 주행 정보에 대한 내용이 publisher형태로 전달됩니다.
     TmapUISDKManager.shared.driveGuidePublisher
     해당 publisher를 이용하여 현재의 속도, 목적지까지의 남은거리 등의 정보를 받을 수 있습니다.

     SDIType, TBTType은 TMapNaviSDKSample/docs/TmapDriveGuide.pdf 문서를 참고하시면 됩니다.
     */
    private func driveInfo(){
        TmapUISDKManager.shared.driveGuidePublisher
            .receive(on: DispatchQueue.main, options: nil)
            .sink(receiveValue: { data in

                print("driveInfo : \(String(describing: data))")

            }).store(in: &authCancelable)

        TmapUISDKManager.shared.requestStop()
    }

    func setAlert(title: String, message: String, actions: [UIAlertAction], on viewController: UIViewController) { // 알람기능 만들어두기
        print("버튼생성 : \(title)")
        let alert = UIAlertController(
            title: title,
            message: message,
            preferredStyle: UIAlertController.Style.alert
        )
        for action in actions {
            alert.addAction(action)
        }
        viewController.present(alert, animated:  true)
    }

    func requestStop() {

        TmapUISDKManager.shared.requestStop() // 안내중인 기능을 종료

        print("네비게이션 종료")
    }

}
