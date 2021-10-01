from django.shortcuts import render, redirect, HttpResponse
from .models import Quotes, User
from django.db import models
from django.contrib import messages
import bcrypt
# Create your views here.

def index(request):
    return render(request, 'login_registration.html')

def main_landing(request):
    if 'user_id' not in request.session:
        return redirect('/')
    context = {
        "user": User.objects.get(id= request.session['user_id']),
        "quotes": Quotes.objects.all()
    }
    return render(request,'quotes_landing.html', context)

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
    return redirect('/quotes')

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
        return redirect('/quotes')

def logout(request):
    request.session.flush()
    return redirect('/')

def create_quote(request):
    if request.method == "GET":
        return redirect('/')

    errors = Quotes.objects.quote_validator(request.POST)

    user = User.objects.get(id=request.session['user_id'])

    if len(errors) > 0:
        for value in errors.values():
            messages.error(request, value)
        return redirect('/quotes')
    else:
        Quotes.objects.create(
            author = request.POST['author'],
            quote = request.POST['quote'],
            uploaded_by = user,
        )

    return redirect('/quotes')

def view_quotes(request, user_id):
    if 'user_id' not in request.session:
        return redirect('/')

    user = User.objects.get(id=request.session['user_id'])
    quote_creator = User.objects.get(id=user_id)
    count = len(quote_creator.quotes_created.all())

    context = {
        "user": user,
        "quote_creator": quote_creator,
        "count" : count,
    }

    return render(request,'view_quote.html', context)


def update(request, quote_id):
    if request.method == "GET":
        return redirect('/')

    errors = Quotes.objects.quote_validator(request.POST)

    if len(errors) > 0:
        for value in errors.values():
            messages.error(request, value)
        return redirect('../../quotes/'+ str(quote_id)+'/edit')
    else:
        #quote
        edit_quote = Quotes.objects.get(id = quote_id)
        #Change Value
        edit_quote.author = request.POST['author']
        edit_quote.quote = request.POST['quote']
        edit_quote.updated_at = models.DateTimeField(auto_now=True)

        edit_quote.save()
        return redirect('../../quotes')

def destroy(request, quote_id):
    destory_quote= Quotes.objects.get(id = quote_id)

    destory_quote.delete()
    return redirect("/quotes")

def edit(request, quote_id):
    if 'user_id' not in request.session:
        return redirect('/')

    user = User.objects.get(id=request.session['user_id'])
    quote = Quotes.objects.get(id=quote_id)

    context = {
        "user": user,
        "quote": quote,
    }

    return render(request,'edit_quote.html', context)