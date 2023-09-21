class UsersController < ApplicationController
  before_action :set_user, only: [:show, :edit, :update, :destroy, :following, :followers]
  before_action :logged_in_user, only: [:index, :edit, :update, :destroy, :following, :followers]
  before_action :correct_user, only: [:edit, :update]
  before_action :admin_user, only: :destroy

  def index
    @users = User.where(activated: true).paginate(page: params[:page])
  rescue
    flash[:error] = 'There was an error fetching the users'
    render 'index'
  end

  def show
    redirect_to root_url unless @user.activated?
    @microposts = @user.microposts.paginate(page: params[:page])
  rescue
    flash[:error] = 'There was an error fetching the user information'
    render 'show'
  end

  def new
    @user = User.new
  end

  def create
    @user = User.new(user_params)
    if @user.save
      @user.send_activation_email
      flash[:info] = 'Please check your email to activate your account.'
      redirect_to root_url
    else
      render 'new'
    end
  rescue
    flash[:error] = 'There was an error creating the user account'
    render 'new'
  end

  def edit; end

  def update
    if @user.update_attributes(user_params)
      flash[:success] = 'Profile updated'
      redirect_to @user
    else
      render 'edit'
    end
  rescue
    flash[:error] = 'There was an error updating the profile'
    render 'edit'
  end

  def destroy
    @user.destroy
    flash[:success] = 'User deleted'
    redirect_to users_url
  rescue
    flash[:error] = 'There was an error deleting the user'
    redirect_to users_url
  end

  def following
    @title = 'Following'
    @users = @user.following.paginate(page: params[:page])
    render 'show_follow'
  rescue
    flash[:error] = 'There was an error fetching the following users'
    render 'show_follow'
  end

  def followers
    @title = 'Followers'
    @users = @user.followers.paginate(page: params[:page])
    render 'show_follow'
  rescue
    flash[:error] = 'There was an error fetching the followers'
    render 'show_follow'
  end

  private

  def set_user
    @user = User.find(params[:id])
  rescue ActiveRecord::RecordNotFound
    flash[:error] = 'The requested user does not exist'
    redirect_to root_url
  end

  def user_params
    params.require(:user).permit(:name, :email, :password, :password_confirmation)
  end

  def correct_user
    redirect_to(root_url) unless current_user?(@user)
  end

  def admin_user
    redirect_to(root_url) unless current_user.admin?
  end
end