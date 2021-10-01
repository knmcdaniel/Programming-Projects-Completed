from django.db import models

# Create your models here.

class ShowsManager(models.Manager):
    def basic_validator(self, postData):
        errors = {}

        if len(postData['title']) < 2:
            errors['title'] = "The Title of the show must be longer than 1 letter."
        if len(postData['network']) < 3:
            errors['network'] = "The Network of the show must be longer than 2 letters."
        if len(postData['description']) < 10:
            errors['description'] = "The description of the show must be longer than 10 letters."
        return errors
    
class Shows(models.Model):
    title = models.CharField(max_length=255)
    network = models.CharField(max_length=255)
    release_date = models.DateTimeField()
    description = models.CharField(max_length=500)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    objects = ShowsManager()