import OSC
c = OSC.OSCClient()
c.connect(('127.0.0.1', 57120))   # connect to SuperCollider
oscmsg = OSC.OSCMessage()
oscmsg.setAddress("/startup")
oscmsg.append(10000)
oscmsg.append(0)
oscmsg.append(0)
c.send(oscmsg)