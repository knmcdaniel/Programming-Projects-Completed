from django.shortcuts import render, redirect, HttpResponse 
from .models import User, UserManager
from django.contrib import messages
import bcrypt
# Create your views here.

def index(request):
    return render(request, 'login_registration.html')

def list_users(request):
    context ={
        "users": User.objects.all()
    }
    return render(request,'users.html', context)

def user_landing(request, user_id):
    if 'user_id' not in request.session:
        return redirect('/')
    context = {
        "user": User.objects.get(id= user_id)
    }
    return render(request,'user_landing.html', context)

def register(request):
    if request.method == "GET":
        return redirect('/')

    errors = User.objects.registration_validator(request.POST)

    if len(errors) > 0:
        for value in errors.values():
            messages.error(request, value)
        return redirect('/')
    else:
        password = request.POST['password']

        pw_hash = bcrypt.hashpw(password.encode(), bcrypt.gensalt()).decode()
        new_user = User.objects.create(
            first_name = request.POST['first_name'],
            last_name = request.POST['last_name'],
            email = request.POST['email'],
            password = pw_hash,
        )
        request.session['user_id'] = new_user.id
    return redirect('/'+ str(new_user.id))

def login(request):
    if request.method == "GET":
        return redirect('/')

    errors = User.objects.login_validator(request.POST)

    if len(errors) > 0:
        for value in errors.values():
            messages.error(request, value)
        return redirect('/')
    else:
        logged_user = User.objects.get(email = request.POST['email'])
        request.session['user_id'] = logged_user.id
        return redirect('/'+ str(logged_user.id))

def logout(request):
    request.session.flush()
    return redirect('/')