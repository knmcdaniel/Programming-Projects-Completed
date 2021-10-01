from django.shortcuts import render, redirect, HttpResponse
from .models import Books, User
from django.db import models
from django.contrib import messages
import bcrypt
# Create your views here.

def index(request):
    return render(request, 'login_registration.html')

def list_users(request):
    context ={
        "users": User.objects.all(),
        "books": Books.objects.all()
    }
    return render(request,'users.html', context)


def main_landing(request):
    if 'user_id' not in request.session:
        return redirect('/')
    context = {
        "user": User.objects.get(id= request.session['user_id']),
        "books": Books.objects.all()
    }
    return render(request,'books_landing.html', context)

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
    return redirect('/books')

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
        return redirect('/books')

def logout(request):
    request.session.flush()
    return redirect('/')

def create_book(request):
    if request.method == "GET":
        return redirect('/')

    errors = Books.objects.book_validator(request.POST)

    user = User.objects.get(id=request.session['user_id'])

    if len(errors) > 0:
        for value in errors.values():
            messages.error(request, value)
        return redirect('/books')
    else:
        
        new_book = Books.objects.create(
            title = request.POST['title'],
            desc = request.POST['desc'],
            uploaded_by = user,
        )

        user.books_favorited.add(new_book)

    return redirect('/books')

def view_books(request, book_id):
    if 'user_id' not in request.session:
        return redirect('/')

    user = User.objects.get(id=request.session['user_id'])
    book = Books.objects.get(id=book_id)

    context = {
        "user": user,
        "book": book
    }

    if book.uploaded_by == user:
        return render(request,'edit_book.html', context)
    else:
        return render(request,'view_book.html', context)

def add_favorite_main(request, book_id):

    user = User.objects.get(id=request.session['user_id'])
    book = Books.objects.get(id=book_id)

    user.books_favorited.add(book)

    return redirect('/books')

def add_favorite_view(request, book_id):

    user = User.objects.get(id=request.session['user_id'])
    book = Books.objects.get(id=book_id)

    user.books_favorited.add(book)

    return redirect('../../books/'+ str(book_id))

def update(request, book_id):
    if request.method == "GET":
        return redirect('/')

    errors = Books.objects.book_validator(request.POST)

    if len(errors) > 0:
        for value in errors.values():
            messages.error(request, value)
        return redirect('../../books/'+ str(book_id))
    else:
        #book
        edit_book = Books.objects.get(id = book_id)
        #Change Value
        edit_book.title = request.POST['title']
        edit_book.desc = request.POST['desc']
        edit_book.updated_at = models.DateTimeField(auto_now=True)

        edit_book.save()
        return redirect('../../=books/'+ str(book_id))

def destroy(request, book_id):
    destory_book= Books.objects.get(id = book_id)

    destory_book.delete()
    return redirect("/books")