from PIL import Image
import urllib2 as urllib
import io

frame = 0

while(True):
    im = urllib.urlopen("http://tatsupi09.local:8080/?action=snapshot")
    image_file = io.BytesIO(im.read())
    im = Image.open(image_file)
    #top_buttom_image = im.transpose(Image.ROTATE_180)
    im.save("./cam9/" + str(frame) + ".jpg")
    frame = frame + 1