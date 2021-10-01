from django.urls import path     
from . import views

urlpatterns = [
    path('', views.index),
    path('user', views.list_users),   #Just used for testing, can only access manually. Obviously not something you would put in production, it just helps me remember the fake emails I've made so I don't repeat them while resting. 
    path('login', views.login),
    path('logout', views.logout),
    path('register', views.register),
    path('books', views.main_landing),
    path('books/create', views.create_book),
    path('books/<int:book_id>/update', views.update),
    path('books/<int:book_id>/destory', views.destroy),
    path('books/<int:book_id>', views.view_books),
    path('books/<int:book_id>/favorite_main', views.add_favorite_main),
    path('books/<int:book_id>/favorite_view', views.add_favorite_view),
    #path('create', views.create),
] 
