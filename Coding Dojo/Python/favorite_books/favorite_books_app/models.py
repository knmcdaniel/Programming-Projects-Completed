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

class BooksManager(models.Manager):
    def book_validator(self, postData):
        errors = {}

        title = postData['title']
        if len(title) < 1:
            errors['title_too_short'] = "Not a valid title."

        description = postData['desc']
        if len(description) < 5:
            errors['desc_too_short'] = "Not a valid description."

        if len(errors) < 0:
            errors['create'] = ("Book Created!")
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
    #Object
    #id
    first_name = models.CharField(max_length=25)
    last_name = models.CharField(max_length=25)
    email = models.CharField(max_length=50)
    password = models.CharField(max_length=50)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    #relationships
    #One to many with Books ---> book_created
    #Many to Many with Favorites ---> books_favorited

    #methods
    objects = UserManager()

    
class Books(models.Model):
    #Object
    #id
    title = models.CharField(max_length=25)
    desc = models.CharField(max_length=25)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    #relationships
    uploaded_by = models.ForeignKey(User, related_name="book_created", on_delete = models.CASCADE)
    users_that_favorited = models.ManyToManyField(User, related_name="books_favorited")
    #methods
    objects = BooksManager()
