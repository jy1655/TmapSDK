//
//  MQTT.swift
//  TmapSDK_pod
//
//  Created by 황재영 on 11/8/23.
//

import CocoaMQTT


class MQTT: CocoaMQTTDelegate {

    

    static let shared = MQTT()
    var topic: String = ""

    private var mqttClient: CocoaMQTT?

    init() {
        let clientID = "iOS_Client_\(String(ProcessInfo().processIdentifier))"
        let mqtt5 = CocoaMQTT5(clientID: clientID, host: "broker.emqx.io", port: 1883)
        
        mqttClient = CocoaMQTT(clientID: clientID, host: "broker.emqx.io", port: 1883)
        mqttClient?.username = "iPhone12_PRO_AidALL"
        mqttClient?.password = "123123"
        mqttClient?.keepAlive = 60
        mqttClient?.delegate = self
    }

    func connect() {
        mqttClient?.connect()
    }

    func disconnect() {
        mqttClient?.disconnect()
    }

    func subscribe(to topic: String) {
        mqttClient?.subscribe(topic)
    }

    func publish(message: String, to topic: String) {
        mqttClient?.publish(topic, withString: message)
    }

    // MARK: - CocoaMQTTDelegate Methods

    func mqtt(_ mqtt: CocoaMQTT, didConnect host: String, port: Int) {
        print("MQTT: Connected to \(host) on port \(port)")
    }

    func mqtt(_ mqtt: CocoaMQTT, didConnectAck ack: CocoaMQTTConnAck) {
        print("MQTT: Connected with ack: \(ack)")
        // Here you can start subscribing to topics
    }

    func mqtt(_ mqtt: CocoaMQTT, didDisconnectWithError err: Error?) {
        if let error = err {
            print("MQTT: Disconnected with error: \(error)")
        } else {
            print("MQTT: Disconnected without error.")
        }
    }

    func mqtt(_ mqtt: CocoaMQTT, didPublishAck id: UInt16) {
        print("MQTT: Message published with id \(id)")
    }

    func mqtt(_ mqtt: CocoaMQTT, didSubscribeTopics success: NSDictionary, failed: [String]) {
        print("MQTT: Subscribed to topic: \(topic)")
    }

    func mqtt(_ mqtt: CocoaMQTT, didUnsubscribeTopics topics: [String]) {
        print("MQTT: Unsubscribed from topic: \(topic)")
    }

    func mqtt(_ mqtt: CocoaMQTT, didReceiveMessage message: CocoaMQTTMessage, id: UInt16) {
        if let string = message.string {
            print("MQTT: Received message: \(string) on topic: \(message.topic)")
        }
    }

    func mqttDidPing(_ mqtt: CocoaMQTT) {
        print("MQTT: Ping")
    }

    func mqttDidReceivePong(_ mqtt: CocoaMQTT) {
        print("MQTT: Pong")
    }

    func mqttDidDisconnect(_ mqtt: CocoaMQTT, withError err: Error?) {
        print("MQTT: Disconnect")
    }

    func mqtt(_ mqtt: CocoaMQTT, didPublishMessage message: CocoaMQTTMessage, id: UInt16) {
        print("MQTT: didPublishMessage \(message)")
    }

}
