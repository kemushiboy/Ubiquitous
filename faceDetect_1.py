# -*- coding: utf-8 -*-
 
import cv2
import subprocess
import os
 
#顔検出器をロード
#cascade_path = "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml"
cascade_path = "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml"
#cascade_path = "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_alt2.xml"
#cascade_path = "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_alt_tree.xml"
face_cascade = cv2.CascadeClassifier(cascade_path)

frameNum = 0
beforeFaceNum = 0
cmd = "python ./facepp-python-sdk/cam1_del.py"
subprocess.call(cmd.strip().split(" "))


while(True):
    
    flug = os.path.exists("./cam1/" +str(frameNum+15) +".jpg")

    if flug:
        print "file exists"
    
        #入力画像の読み込み
        img = cv2.imread("./cam1/" +str(frameNum) +".jpg")
        if hasattr(img, "shape"):
            if(img.data):
                #gray scaleヘ変換
                gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
                print "convert COLOR_BGR2GRAY"
    
                #顔検出
                faces = face_cascade.detectMultiScale(gray, 1.3, 1)
                print "detect Faces"
    
                if len(faces) > 0:
                #顔があったらfacepp実行
                #print "faceNum = " + str(len(faces))
                #if len(faces) > beforeFaceNum:
                    #赤枠
                    #for (x,y,w,h) in faces:
                        #cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,255),2)
    
                    #結果の表示
                    #cv2.imshow('img',img)
                    #cv2.waitKey(0)
                    #cv2.destroyAllWindows()
                    print "frameNum = " + str(frameNum)
                    cmd = "python ./facepp-python-sdk/cam1.py " +str(frameNum) +".jpg"
                    #subprocess.call(cmd, shell=True)
                    subprocess.call(cmd.strip().split(" "))
                    frameNum = frameNum+5
                    #api節約のため、顔があった場合フレームを多く進める
            
                else:
                    print "frameNum = " + str(frameNum) + "face does not found"
                    #次のフレームへ
                    frameNum = frameNum+1

            #前フレームでの顔の数を記憶
                beforeFaceNum = len(faces)
        else:
            print"cannot read image"
    #else:
        #print "file does not exist"

