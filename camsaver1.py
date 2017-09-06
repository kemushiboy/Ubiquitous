from PIL import Image
import urllib2 as urllib
import io

frame = 0

while(True):
    im = urllib.urlopen("http://tatsupi01.local:8080/?action=snapshot")
    print "url open"
    image_file = io.BytesIO(im.read())
    im = Image.open(image_file)
    top_buttom_image = im.transpose(Image.ROTATE_180)
    top_buttom_image.save("./cam1/" + str(frame) + ".jpg")
    print "save image"
    frame = frame + 1