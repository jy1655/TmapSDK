//
//  ViewController.swift
//  Tmap
//
//  Created by 황재영 on 11/6/23.
//

import UIKit
import TMapSDK
import TmapUISDK
import TmapNaviSDK
import VSMSDK

class ViewController: UIViewController, TMapTapiDelegate {

    let navigation = Navigation.shared
    var mapView: TMapView! // TMapView의 인스턴스를 저장할 변수를 선언합니다
    var installed: Bool = TMapApi.isTmapApplicationInstalled() // 티맵 App 설치 여부를 판단한다 - 사용여부 불확실
    var gpsStatus: String?
    var origin: Point? // 출발지(Optional), 입력값이 없을경우 현재위치로 설정됨
    var destination: Point? // 목적지
    var waypoint: Point? // 경유지 (Optional)

    weak var mapContainerView: UIView! // 지도를 추가할 컨테이너 뷰입니다.


    override func viewDidLoad() {
        super.viewDidLoad()

        setupMapView()

        detectStatus()

        setUpUI()

    }



    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

    }

    @objc func qwer() {
        let des = Point(longitude: 126.977751, latitude: 37.566248, name: "시청")
        print("경로탐색")
        return navigation.requestNavi(origin: nil, destination: des, waypoint: nil)
    }

    @objc func locationCheck(){
        let status = CLLocationManager.authorizationStatus()

        if status == CLAuthorizationStatus.denied || status == CLAuthorizationStatus.restricted {


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
        }
    }

    func setupMapView() {
        // TMapView 객체를 생성합니다.
        mapView = TMapView()

        mapView?.setApiKey(getValue(forKey: "appKey")!)

        // 필요한 경우, 여기에 추가적인 mapView 설정을 추가할 수 있습니다.
        // 예: mapView.setCenter(...)

        // mapView를 self.view에 추가합니다.
        self.view.addSubview(mapView)

        // 오토레이아웃을 사용하여 mapView의 제약 조건을 설정합니다.
        mapView.translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate([
            mapView.topAnchor.constraint(equalTo: self.view.topAnchor),
            mapView.leftAnchor.constraint(equalTo: self.view.leftAnchor),
            mapView.rightAnchor.constraint(equalTo: self.view.rightAnchor),
            // 하단을 비우기 위해 'mapView'의 하단을 뷰의 중간에 맞춥니다.
            mapView.bottomAnchor.constraint(equalTo: self.view.bottomAnchor)
        ])
    }

    func setUpUI() {
        navigation.setConfig()
        setButton(title: "경로탐색", selector: #selector(qwer))

    }

    func detectStatus() { // 처음 실행시 상태 확인용

        let action1 = UIAlertAction(title: "확인", style: .default, handler: { _ in print("버튼 눌림") } )

        if gpsStatus == "NO_SIGNAL" {
            print("GPS 신호 없음")
            setAlert(title: "GPS 오류!", message: "GPS 신호가 없습니다!", actions: [action1])
        } else if gpsStatus == "BAD" {
            print("GPS 신호가 약합니다")
        } else if gpsStatus == "TUNNEL" {
            print("터널진입")
        } else if gpsStatus == "UNDERPASS" {
            print("Underpass")
        } else {
            print("상태양호")
        }

        if !installed { // 티맵 App 설치 여부를 판단하여 알림창 발생
            setAlert(title: "알림", message: "Tmap 이 설치되어 있지 않아 경로검색에 어려움이 있을 수 있습니다", actions: [action1])
        }
    }

    func setAlert(title: String, message: String, actions: [UIAlertAction]) { // 알람기능 만들어두기
        let alert = UIAlertController(
            title: title,
            message: message,
            preferredStyle: UIAlertController.Style.alert
        )
        for action in actions {
            alert.addAction(action)
        }
        self.present(alert, animated:  true)
    }

    func setButton(title: String, selector: Selector) { // 버튼 만들기
        // iOS 14 미만에서 사용하는 기존의 UIButton 초기화 방식
        let button = UIButton(frame: CGRect(x: 100, y: 100, width: 200, height: 50))
        button.setTitle(title, for: .normal)
        button.addTarget(self, action: selector, for: .touchUpInside) // selector로 버튼 클릭시 구현될 메소드 작성
        self.view.addSubview(button)
    }

    func SKTMapApikeySucceed() { // TMapTapiDelegate를 통해 callback을 받음.
        print("APIKEY 인증 성공")
    }

    func SKTMapApikeyFailed(error: NSError?) {
        print("APIKEY 인증 실패")
    }

    func getValue(forKey key: String) -> String? {
        guard let path = Bundle.main.path(forResource: "Config", ofType: "plist"),
              let dict = NSDictionary(contentsOfFile: path) as? [String: AnyObject] else {
            return nil
        }
        return dict[key] as? String
    } // Client_ID 값을 불러오기 위한 메소드
}
