//
//  Navigation.swift
//  TmapSDK_pod
//
//  Created by 황재영 on 11/6/23.
//

import TmapUISDK
import TmapNaviSDK

class Navigation {

    static let shared = Navigation()

    var sdkConfig = UISDKConfigOption()
    


    func setConfig() {

        sdkConfig.carType = .normal                         // 자동차의 종류를 설정합니다.
        sdkConfig.fuelType = .gas                           // 자동차의 유종을 설정합니다.
        sdkConfig.showTrafficAccident = true                // map상에서 유고정보(사고정보) 및 교통량의 표시여부를 설정합니다.
        sdkConfig.mapTextSize = .large                      // map의 text의 크기를 설정합니다.
        sdkConfig.nightMode = .auto                         // dark mode의 동작여부를 설정합니다.
        sdkConfig.isUseSpeedReactMapScale = true            // 속도반응형 지도의 사용여부를 설정합니다.
        sdkConfig.isShowTrafficInRoute = true               // 안내되는 경로상에 교통량의 표시여부를 설정합니다.
        TmapUISDKManager.shared.setConfig(config: sdkConfig)
    }


    func requestNavi(origin: Point?, destination: Point, waypoint: [Point]?) { // 경로 설정

        if !(waypoint == nil) {
            print("경유지 없음")
            return TmapUISDKManager.shared.requestRoute(origin: origin, destination: destination, wayPoints: waypoint!)
        } else {
            print("경유지 있음")
            return TmapUISDKManager.shared.requestRoute(origin: origin, destination: destination)
        }
    }

    func requestStop() {

        TmapUISDKManager.shared.requestStop() // 안내중인 기능을 종료

        print("네비게이션 종료")
    }

}
