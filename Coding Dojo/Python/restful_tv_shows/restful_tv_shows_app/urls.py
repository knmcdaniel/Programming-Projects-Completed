from django.urls import path
from . import views, models

urlpatterns = [
    path('', views.index),
    path('shows', views.index),
    path('shows/create', views.create),
    path('shows/new', views.NewShow),
    path('shows/<int:show_id>/edit', views.EditShow),
    path('shows/<int:show_id>/update', views.Update),
    path('shows/<int:show_id>/describe', views.DescribeShow),
    path('shows/<int:show_id>/delete', views.delete),
]