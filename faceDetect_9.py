# -*- coding: utf-8 -*-
 
import cv2
import subprocess
import os
import OSC
 
#顔検出器をロード
#cascade_path = "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml"
cascade_path = "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml"
#cascade_path = "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_alt2.xml"
#cascade_path = "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_alt_tree.xml"
face_cascade = cv2.CascadeClassifier(cascade_path)

frameNum = 0
beforeFaceNum = 0
resetbuffer=30
sendbuffer = 5

#cmd = "python ./facepp-python-sdk/cam9_del.py"
#subprocess.call(cmd.strip().split(" "))


while(True):
    flug = os.path.exists("./cam9/" +str(frameNum+15) +".jpg")

    if flug:
        #print "file exists"
    
        #入力画像の読み込み
        img = cv2.imread("./cam9/" +str(frameNum) +".jpg")
        if hasattr(img, "shape"):
            if(img.data):
                #gray scaleヘ変換
                gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
                #print "convert COLOR_BGR2GRAY"
    
                #顔検出
                faces = face_cascade.detectMultiScale(gray, 1.3, 1)
                #print "detect Faces"
    
                if len(faces) > 0:
                    resetbuffer = 15
                    
                    if sendbuffer > 0:
                        sendbuffer = sendbuffer-1
                    elif sendbuffer == 0:
                        client = OSC.OSCClient()
                        client.connect(('127.0.0.1', 8000))
                        msg = OSC.OSCMessage()
                        msg.setAddress("/capture")
                        filename = str(frameNum) +".jpg"
                        msg.append(filename)
                        client.send(msg)
                        sendbuffer = sendbuffer-1
                        print "sendOSC"
                        #sendbuffer = 75
            

                else:
                    if resetbuffer > 0:
                        resetbuffer = resetbuffer - 1
                    else:
                   
                   #client2 = OSC.OSCClient()
                   #    client2.connect(('127.0.0.1', 57120))
                   #    msg2 = OSC.OSCMessage()
                   #    msg2.setAddress("/reset")
                   #    filename = str(frameNum) +".jpg"
                   #    msg2.append(filename)
                   #    client2.send(msg2)
                        print "Reset"
                        sendbuffer = 5
                            #resetbuffer = 15
                    
                
                

            #前フレームでの顔の数を記憶
                frameNum = frameNum+1
                beforeFaceNum = len(faces)
#else:
#print"cannot read image"
    #else:
        #print "file does not exist"

