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
import CoreLocation

class ViewController: UIViewController, TMapTapiDelegate, TMapViewDelegate, CLLocationManagerDelegate {

    let navigation = Navigation.shared
    let pathData = TMapPathData() // 경로 탐색을 위한 지정
    var mapView: TMapView! // TMapView의 인스턴스를 저장할 변수를 선언합니다
    var installed: Bool = TMapApi.isTmapApplicationInstalled() // 티맵 App 설치 여부를 판단한다 - 사용여부 불확실
    var path = Array<CLLocationCoordinate2D>()
    var locationManager: CLLocationManager!
    var currentLocation: CLLocationCoordinate2D!
    var gpsStatus: String = "UNKNOWN" { didSet { detectStatus() } } // GPS 상태변화 확인용
    var origin: Point? // 출발지(Optional), 입력값이 없을경우 현재위치로 설정됨
    var destination: Point? // 목적지
    var waypoint: Point? // 경유지 (Optional)
    var markers: [TMapMarker] = []

    weak var mapContainerView: UIView! // 지도를 추가할 컨테이너 뷰입니다.


    override func viewDidLoad() {
        super.viewDidLoad()

        setupMapView()
        setUpUI()


    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        navigation.locationCheck(on: self)

        // 위치 관리자 설정
        locationManager = CLLocationManager()
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBestForNavigation // 최상의 정확도
        locationManager.distanceFilter = 30 // 30미터마다 위치업데이트를 받음
//        locationManager.distanceFilter = kCLDistanceFilterNone // 미세한 움직임에 대한 피드백도 받음

        locationManager.requestWhenInUseAuthorization() // 위치 서비스 권한 요청
        locationManager.requestAlwaysAuthorization() // 언제나?
        locationManager.startUpdatingLocation() // 위치 업데이트 시작
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

    }

    @objc func requestRoute() {

        mapView.trackingMode = .follow // 트래킹 모드 활성화
        var status = mapView.trackingMode // 트래킹 모드 활성화 여부


        let startPoint = currentLocation!

        let des = CLLocationCoordinate2D(latitude: 37.403049, longitude: 127.103318)

        path.append(startPoint)
        path.append(des)

        let polyline = TMapPolyline(coordinates: path)

        let pathType = TMapPathType.PEDESTRIAN_PATH
        print("경로탐색")
        pathData.findPathDataWithType(pathType, startPoint: startPoint, endPoint: des) { (result, error)->Void in
            // 결과
            if let error = error {
                    // 에러 처리
                    print("Error: \(error.localizedDescription)")
            } else if let polyline = result {
                    // 경로 데이터 사용
                    print("Path data received")
                    DispatchQueue.main.async { // UI 업데이트는 메인 스레드에서 수행합니다.
                        let marker1 = TMapMarker(position: startPoint) // `pathData` 폴리라인을 지도에 추가합니다.
                        marker1.map = self.mapView
                        marker1.title = "출발지"
//                        self.markers.append(marker1)

                        let marker2 = TMapMarker(position: des)
                        marker2.map = self.mapView
                        marker2.title = "목적지"
//                        self.markers.append(marker2)

                        polyline.map = self.mapView
                        self.mapView.fitMapBoundsWithPolylines([polyline])
//                        self.polylines.append(polyline)
//                        self.mapView?.fitMapBoundsWithPolylines(self.polylines)
                        }
                }
            }
        }

    func setupMapView() {
        // TMapView 객체를 생성합니다.
        mapView = TMapView()

        mapView.delegate = self // 지도 상호작용을 위해 추가
        mapView.isUserInteractionEnabled = true // 지도 상호작용을 위해 추가

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

    func searchLocation(keyword: String) {
        pathData.requestFindAllPOI(keyword, count: 30, completion: {
            (result, error) -> Void in
            print(result as? String ?? <#default value#>)
        })
    }

    func setUpUI() {
        setButton(title: "경로탐색", selector: #selector(requestRoute))

    }

    func detectStatus() {

        let action1 = UIAlertAction(title: "확인", style: .default, handler: { _ in print("버튼 눌림") } )

        if gpsStatus == "NO_SIGNAL" {
            print("GPS 신호 없음")
                navigation.setAlert(title: "GPS 오류!", message: "GPS 신호가 없습니다!", actions: [action1], on: self)
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
            navigation.setAlert(title: "알림", message: "Tmap 이 설치되어 있지 않아 경로검색에 어려움이 있을 수 있습니다", actions: [action1], on: self)
        }
    }

//    func fitLocationBounds(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) { // 위치 관리자가 새로운 위치 정보를 수신할 때마다 호출되어야 하는 델리게이트 메소드
//        if let location = locations.last {
//            currentLocation = location.coordinate
//
//            // 사용자의 현재 위치를 기준으로 남서쪽과 북동쪽 경계를 계산합니다.
//            let span = 0.005 // 예를 들어, 현재 위치에서 0.005도 떨어진 거리
//            let sw = CLLocationCoordinate2D(latitude: currentLocation.latitude - span, longitude: currentLocation.longitude - span)
//            let ne = CLLocationCoordinate2D(latitude: currentLocation.latitude + span, longitude: currentLocation.longitude + span)
//
//            // 그 경계를 MapBounds 객체에 설정합니다.
//            let bounds = MapBounds(sw: sw, ne: ne)
//
//            // fitBounds 메소드를 호출하여 지도가 해당 영역을 표시하도록 합니다.
//            mapView.fitBounds(bounds)
//        }
//    }

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) { // 위치 정보가 업데이트 되었을 때 호출되는 델리게이트 메소드
        if let location = locations.last { // 최신 위치 정보를 가져옵니다.
            let latitude = location.coordinate.latitude
            let longitude = location.coordinate.longitude

            currentLocation = CLLocationCoordinate2D(latitude: latitude, longitude: longitude) // CLLocationCoordinate2D로 변환

            print("Current coordinates: \(String(describing: currentLocation))") // 여기서 coordinate를 사용할 수 있습니다.
            }
    }

        // 위치 접근이 실패했을 때 호출되는 메소드
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
            print("Error getting location: \(error.localizedDescription)")
    }

    func mapView(_ mapView: TMapView, tapOnMap position: CLLocationCoordinate2D) { // 탭부분만 콜백이 안됨
        print("지도 탭")
        let lat: Double = position.latitude
        let lon: Double = position.longitude
        print("lat:\(lat) \n lon:\(lon)")


//                    let marker = TMapMarker(position: position)
//                    marker.title = "제목없음"
//                    marker.subTitle = "내용없음"
//                    marker.draggable = true
//                    let label = UILabel(frame: CGRect(x: 0, y: 0, width: 30, height: 50))
//                    label.text = "좌측"
//                    marker.leftCalloutView = label
//                    let label2 = UILabel(frame: CGRect(x: 0, y: 0, width: 30, height: 50))
//                    label2.text = "우측"
//                    marker.rightCalloutView = label2
//
//                    marker.map = self.mapView
//                    self.markers.append(marker)

    }

    func mapView(_ mapView: TMapView, longTapOnMap position: CLLocationCoordinate2D) {
        print("지도 길게 탭")
        let lat: Double = position.latitude
        let lon: Double = position.longitude
        print("lat:\(lat) \n lon:\(lon)")
    }

    func mapView(_ mapView: TMapView, doubleTapOnMap position: CLLocationCoordinate2D) {
        print("지도 더블 탭")

        let marker = TMapMarker(position: position)

        setMarker(position: position)

            //        let label = UILabel(frame: CGRect(x: 0, y: 0, width: 30, height: 50))
            //        label.text = "좌측"
            //        marker.leftCalloutView = label
            //        let label2 = UILabel(frame: CGRect(x: 0, y: 0, width: 30, height: 50))
            //        label2.text = "우측"
            //        marker.rightCalloutView = label2
    }

    func mapView(_ mapView: TMapView, tapOnMarker marker: TMapMarker) {
        print("마커 탭")
    }

    func setMarker(position: CLLocationCoordinate2D) { // 마커 생성시 리버스지오코딩으로 주소 가져오기
        pathData.reverseGeocoding(position, addressType: "A02") {(result, error) in
            if let result = result {
                DispatchQueue.main.async {
                    let marker = TMapMarker(position: position)
                    marker.map = self.mapView
                    marker.draggable = false
                    marker.title = result["fullAddress"] as? String
                    marker.subTitle = result["buildingName"] as? String
                    self.markers.append(marker)
                }
            }
        }
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
