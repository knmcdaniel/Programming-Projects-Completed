from django.db import models
import bcrypt, re

# Create your models here.

class UserManager(models.Manager):
    def registration_validator(self, postData):
        errors = {}

        password = postData['password']
        confirm_password = postData['confirm_password']
        if password != confirm_password:
            errors['non_matching_passwords'] = "Your Passwords do not match"

        email = User.objects.filter(email=postData['email'])
        if email:
            errors['unique'] = "Email Taken"
        
        EMAIL_REGEX = re.compile(r'^[a-zA-Z0-9.+_-]+@[a-zA-Z0-9._-]+\.[a-zA-Z]+$')
        if not EMAIL_REGEX.match(postData['email']):    # test whether a field matches the pattern            
            errors['email'] = ("Invalid email address!")

        if len(errors) < 0:
            errors['create'] = ("User Created!")
        return errors
        
    def login_validator(self, postData):
        errors = {}
        email = User.objects.filter(email=postData['email'])
        if not email:
            errors['creds'] = "Invalid Credentials"
        else:
            logged_user = email[0]
            if not bcrypt.checkpw(postData['password'].encode(),logged_user.password.encode()):
                errors['creds'] = "Invalid Credentials"

        return errors
    
class User(models.Model):
    first_name = models.CharField(max_length=25)
    last_name = models.CharField(max_length=25)
    email = models.CharField(max_length=50)
    password = models.CharField(max_length=50)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    objects = UserManager()
