package require zmq

zmq context context 1
zmq socket responder context REP
responder bind "tcp://*:5555"

while {1} {
    zmq message request
    responder recv request
    puts "Received [request data]"
    request close

    zmq message reply -data "World @ [clock format [clock seconds]]"
    responder send reply
    reply close
}
responder close
context term

