//
//  MQTT.swift
//  TmapSDK_pod
//
//  Created by 황재영 on 11/8/23.
//

//import CocoaMQTT
//
//
//class MQTT: CocoaMQTTDelegate {
//    
//
//    static let shared = MQTT()
//
//    private var mqttClient: CocoaMQTT?
//
//    init() {
//        let clientID = "iOS_Client_\(String(ProcessInfo().processIdentifier))"
//        mqttClient = CocoaMQTT(clientID: clientID, host: "your.mqtt-broker.address", port: 1883)
//        mqttClient?.username = "your_username"
//        mqttClient?.password = "your_password"
//        mqttClient?.keepAlive = 60
//        mqttClient?.delegate = self
//    }
//
//    func connect() {
//        mqttClient?.connect()
//    }
//
//    func disconnect() {
//        mqttClient?.disconnect()
//    }
//
//    func subscribe(to topic: String) {
//        mqttClient?.subscribe(topic)
//    }
//
//    func publish(message: String, to topic: String) {
//        mqttClient?.publish(topic, withString: message)
//    }
//
//    // MARK: - CocoaMQTTDelegate Methods
//
//    func mqtt(_ mqtt: CocoaMQTT, didConnect host: String, port: Int) {
//        print("MQTT: Connected to \(host) on port \(port)")
//    }
//
//    func mqtt(_ mqtt: CocoaMQTT, didConnectAck ack: CocoaMQTTConnAck) {
//        print("MQTT: Connected with ack: \(ack)")
//        // Here you can start subscribing to topics
//    }
//
//    func mqtt(_ mqtt: CocoaMQTT, didDisconnectWithError err: Error?) {
//        if let error = err {
//            print("MQTT: Disconnected with error: \(error)")
//        } else {
//            print("MQTT: Disconnected without error.")
//        }
//    }
//
//    func mqtt(_ mqtt: CocoaMQTT, didReceiveMessage message: CocoaMQTTMessage, id: String) {
//        if let string = message.string {
//            print("MQTT: Received message: \(string) on topic: \(message.topic)")
//        }
//    }
//
//    func mqtt(_ mqtt: CocoaMQTT, didSubscribeTopic topic: String) {
//        print("MQTT: Subscribed to topic: \(topic)")
//    }
//
//    func mqtt(_ mqtt: CocoaMQTT, didUnsubscribeTopic topic: String) {
//        print("MQTT: Unsubscribed from topic: \(topic)")
//    }
//
//    // ... (Other delegate methods as needed)
//}
