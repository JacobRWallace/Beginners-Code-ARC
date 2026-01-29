import os
import time
import random
from instabot import Bot
from PIL import Image

# Instagram credentials
IGUSER = "ten_thousand_eggs"
PASSWD = "password010101"

# Path to photos and default caption
PhotoPath = "C:/Users/wal09545/Documents/VSCode/P1_InstagramPoster/image"
IGCaption = "Default caption here"

# Initialize bot
bot = Bot()

# Login to Instagram with cookies
bot.login(username=IGUSER, password=PASSWD, use_cookie=True)

# Check photo directory
if not os.path.exists(PhotoPath):
    print(f"Photo path {PhotoPath} does not exist.")
    exit()

# Get the list of files in the directory
ListFiles = sorted([f for f in os.listdir(PhotoPath) if os.path.isfile(os.path.join(PhotoPath, f))])
print(f"Total photos in this folder: {len(ListFiles)}")
print(ListFiles)

def preprocess_image(photo_path):
    """Ensure image meets Instagram requirements."""
    img = Image.open(photo_path)
    img = img.convert("RGB")
    img.save(photo_path, quality=95)

# Upload photos
for i, photo in enumerate(ListFiles):
    try:
        photo_path = os.path.join(PhotoPath, photo)
        print(f"Progress: {i + 1} of {len(ListFiles)}")
        print(f"Now uploading this photo to Instagram: {photo}")

        # Preprocess the image
        preprocess_image(photo_path)

        # Upload the photo
        bot.upload_photo(photo_path, caption=IGCaption)

        # Remove the file if uploaded successfully
        remove_me_file = photo_path + ".REMOVE_ME"
        if os.path.exists(remove_me_file):
            os.remove(remove_me_file)
        else:
            print(f"File not found for deletion: {remove_me_file}")

        # Sleep for a random time between uploads
        sleep_time = random.randint(60, 120)
        print(f"Sleeping for {sleep_time} seconds...")
        time.sleep(sleep_time)
    except Exception as e:
        print(f"Error uploading {photo}: {e}")

print("All photos uploaded successfully!")
