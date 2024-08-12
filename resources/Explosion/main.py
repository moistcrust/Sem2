from PIL import Image
import os

def resize_images(target_width, target_height):
    # Get the directory of the current script
    directory = os.path.dirname(os.path.abspath(__file__))
    
    # Loop through all files in the directory
    for filename in os.listdir(directory):
        if filename.lower().endswith('.png'):
            # Open an image file
            with Image.open(os.path.join(directory, filename)) as img:
                # Resize image
                resized_img = img.resize((target_width, target_height), Image.LANCZOS)

                
                # Save resized image, overwrite original
                resized_img.save(os.path.join(directory, filename))
                print(f"Resized and saved: {filename}")

# Example usage: Resize all PNGs to 800x600
resize_images(81, 76)